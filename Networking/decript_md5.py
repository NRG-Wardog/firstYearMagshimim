import hashlib
import itertools
import string
from multiprocessing import Pool, cpu_count

def md5_crack_worker(args):
    md5_hash, length, chars, start, end = args
    for guess_tuple in itertools.islice(itertools.product(chars, repeat=length), start, end):
        guess = ''.join(guess_tuple)
        if hashlib.md5(guess.encode()).hexdigest() == md5_hash:
            return guess
    return None

def md5_crack(md5_hash, max_length=5):
    characters = string.ascii_letters + string.digits
    pool = Pool(cpu_count())
    chunk_size = 10000  # Adjust based on system memory and performance

    for length in range(1, max_length + 1):
        tasks = [(md5_hash, length, characters, i, i + chunk_size)
                 for i in range(0, len(characters) ** length, chunk_size)]

        for result in pool.imap_unordered(md5_crack_worker, tasks):
            if result:
                pool.terminate()
                return result

    pool.close()
    pool.join()
    return None

# Example usage
md5_hash = 'md5_example'
original_input = md5_crack(md5_hash)

if original_input:
    print(f'Original input: {original_input}')
else:
    print('Input not found within given constraints.')
