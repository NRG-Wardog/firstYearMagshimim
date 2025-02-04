import socket
import datetime

ERROR_CODE_OF_DATA = 5
ERROR_CODE = 999.0
SERVER_PORT = 77
SERVER_IP = 'ip'
MESSAGE = "100:REQUEST:city={}&date={}&checksum={}"

"""
function to calculate the checksum of a string
:param str: the string to calculate the checksum
:return: the checksum of the string
"""
def calculate_checksum(string):
    return sum(ord(char.lower())-96 for char in string)

"""
function to calculate the checksum of a date
:param date: the date to calculate the checksum
:return: the checksum of the date
"""
def calculate_date_checksum(date):
    day, month, year = map(int, date.split('/'))
    return sum(map(int, str(day))) + sum(map(int, str(month))) + sum(map(int,str(year)))
"""
function to calculate the checksum of a city
:param city: the city to calculate the checksum
:return: the checksum of the city
"""
def calculate_checksumAll(city, date):
    city_checksum = calculate_checksum(city)
    date_checksum = calculate_date_checksum(date)
    return str(city_checksum) + '.' + str(date_checksum)

"""
function to check the forecast
:param city: the city to check the forecast
:param date: the date to check the forecast
:return
"""
def check_forecast(city, date):
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.connect((SERVER_IP, SERVER_PORT))
    data = server_socket.recv(1024)
    server_socket.send((MESSAGE.format(city, date, calculate_checksumAll(city, date))).encode())

    data = server_socket.recv(1024)
    if(data.decode()[0] == ERROR_CODE_OF_DATA):
        data = data.decode().split(":")
        if(data[2] == "date illegal"):
            return ("Date illegal",ERROR_CODE)
        else:
            return ("Unknown City",ERROR_CODE)


    date,city,temp,temprture,text = map(str, data.decode().split("="))
    temprture,word = map(str,temprture.split("&"))

    server_socket.close()

    return (text,temprture)

"""
function to expand the functionality
:param name: the name of the user
:param city_name: the city name of the user
:return: None
"""
def expand_functionality(city):
    print("welcome!")
    menu = """
MENU:
1. Weather of today
2. News of the weather to today and 3 days after 
    """
    print(menu)

    flag = True
    today = datetime.datetime.today()
    while flag:
        choice = input("Please select an option 1 or 2: ")
        if choice == '1':
            print("Here's the weather for today.")
            date = today.strftime("%d/%m/%Y")
            taple_get= check_forecast(city, date)
            print(date,", Temperature:",taple_get[1],",",taple_get[0],".")
            flag = False
        elif choice == '2':
            print("Weather for 3 days:")
            for i in range(3):
                date = (today + datetime.timedelta(days=i))
                date = date.strftime("%d/%m/%Y")
                taple_get= check_forecast(city, date)
                print(date,", Temperature:",taple_get[1],",",taple_get[0],".")

            flag = False
        else:
            print("Invalid choice. Please select 1 or 2.")


def main():
    city = input("Please enter your city name: ")
    expand_functionality(city)


if __name__ == '__main__':
    main()
