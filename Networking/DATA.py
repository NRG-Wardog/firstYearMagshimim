ALB = {}
SONGS = {}


def parse():
    song = ""
    alb = ""
    with open("Pink_Floyd_DB.txt", "r") as file:
        for line in file:
            line = line.strip()
            if line.startswith("#"):
                line = line.replace("#", "")
                alb, dateAlb = line.split("::")
                ALB[alb] = []
            elif line.startswith("*"):
                line = line.replace("*", "")
                song, writer, lenSong, lyrics = line.split("::")
                ALB[alb].append(song)
                SONGS[song] = [writer, lenSong, lyrics]
            else:
                if song in SONGS:
                    SONGS[song][2] += "" + line

"""
func return list of albums
return :param: alb_key:type:string
"""
def list_albums():
    return " , ".join(ALB.keys())

"""
func return list of songs in the album
:param data:type:string
"""
def list_songs_in_album(data):
    return ",".join(ALB[data])

"""
func return the length of a song
:param data:type:string
return str
"""
def get_song_length(data):
    return str(SONGS[data][1])

"""
func return the lyrics of a song
:param data:type:string
return str
"""
def get_song_lyrics(data):
    return str(SONGS[data][2])

"""
func return which album the song is in
:param data:type:string
return :param: alb_key:type:string
"""
def find_album_by_song(data):
    for alb_key, album in ALB.items():
        if data in album:
            return str(alb_key)
    return "Album not found"
"""
func return songs having the word in their name
:param data:type:string
return :param message:type:str
"""
def search_songs_by_keyword_in_title(data):
    message = ""
    for songKey, song in SONGS.items():
        if data in songKey:
            message += songKey + " "
    if message != "":
        return message
    else:
        return "There is no song"

"""
func return songs having the word in the lyrics
:param data:type:string
return :param message:type:str
"""
def search_songs_by_keyword_in_lyrics(data):
    message = ""
    for songKey, song in SONGS.items():
        if data in song[2]:
            message += songKey + " "
    if message != "":
        return message
    else:
        return "There is no song"



def play(option,data=""):
    parse()
    if option == 1:
        # Send list of albums
        response = list_albums()
    elif option == 2:
        # Send list of songs in the album
        response = f"Songs in {data}:" + list_songs_in_album(data)
    elif option == 3:
        # Send the length of a song
        response = get_song_length(data)
    elif option == 4:
        # Send lyrics of a song
        response = f"The Lyrics of the song({data}) is:" + get_song_lyrics(data)
    elif option == 5:
        # Send which album the song is in
        response = find_album_by_song(data)
    elif option == 6:
        # Send songs having the word in their name
        response = search_songs_by_keyword_in_title(data)
    elif option == 7:
        # Send songs having the word in the lyrics
        response = search_songs_by_keyword_in_lyrics(data)
    elif option == 8:
        return False

    return response
