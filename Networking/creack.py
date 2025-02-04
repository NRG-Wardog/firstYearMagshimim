import re

message = b"FLY008tokabiwn_ml5=00000000000000000000000000000000,iizpwrb=cnaetektmd,tqmm=15:52,tave=eirbh.jcp,vmhqcte=2554,nlg"

def respond(text):
    text = text.decode('utf-8')
    text = re.sub(r'DAT', '', text)
    text = re.sub(r'ERR', '', text)
    text = re.sub(r'FLY', '', text)
    text = re.sub(r'\*\*\*', '', text)
    match = re.search(r'\b\d/10:', text)
    decrypted_text = decrypt_text(text.strip())

def decrypt_text(text):
    result = ""
    decrept = 3

    if len(text) >= 3 and text[:2] == '00' and text[2].isdigit():
        number = int(text[2])
        if 0 <= number <= 10:
            decrept = number
            text = text[3:]  # Remove the '00' and the number
    elif len(text) >= 3 and text[:1] == '0' and text[1:3].isdigit():
        number = int(text[1:3])
        if 0 <= number <= 10:
            decrept = number
            text = text[3:]

    for i, char in enumerate(text):
        if i % 2 == 0 and char.isalpha():
            new_char = chr(((ord(char) - ord('a') - decrept) % 26) + ord('a'))
        else:
            new_char = char
        result += new_char
    print(result)


respond(message)
