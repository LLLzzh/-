import os
import sys
import random
import traceback
import importlib

solution = None

def q1_input(i):
    if i == 9:
        return '0'
    ret = str(random.randint(1, 10**(i**2)))
    return ret+'\n'

def q2_input(i):
    ret = ''
    used = []
    N = random.randint(1, 11)
    ret += str(N)+'\n'
    for i in range(N):
        cur = random.randint(1, 51)
        while cur in used:
            cur = random.randint(1, 51)
        used.append(cur)
        ret += str(cur) + '\n'
    return ret

def q3_input(i):
    ret = ''
    length = random.randint(5, 200)
    dic = '!@#$%^&*()_+1234567890-=qwertyuiop[]QWERTYUIOP{}\\|asdfghjkl;\'ASDFGHJKL:"zxcvbnm,./ZXCVBNM<>?'
    for i in range(length):
        word_length = random.randint(2, 10)
        for j in range(word_length):
            ret += dic[random.randint(0, len(dic)-1)]
        ret += ' '
    return ret[:-1] + '\n'

def q4_input(i):
    n = random.randint(0, 15)
    m = random.randint(n, 15)
    ret = str(m) + ' ' + str(n) + '\n'
    return ret

def q5_input(i):
    return ''

def q6_input(i):
    ret = ''
    n = random.randint(2, 50)
    ret += str(n) + '\n'
    for cnt in range(n):
        ret += str(random.randint(1, 60)) + ' '
    return ret[:-1] + '\n'

def answer_generator(question_folder_name, output_file_path, input_filepath):
    global solution
    temp_stdin = sys.stdin
    temp_stdout = sys.stdout
    sys.stdin = open(input_filepath, 'r')
    sys.stdout = open(output_file_path, 'w')
    if not solution:
        solution = importlib.import_module(question_folder_name+'.solution')
    else:
        importlib.reload(solution)
    sys.stdout.flush()
    sys.stdin.close()
    sys.stdout.close()
    sys.stdin = temp_stdin
    sys.stdout = temp_stdout

def input_generator(output_file_path, content):
    f = open(output_file_path, 'w')
    f.write(content)
    f.close()
    return output_file_path

def main(sub_folder_name):
    solution = None
    data_function = {
        'q1':q1_input,
        'q2':q2_input,
        'q3':q3_input,
        'q4':q4_input,
        'q5':q5_input,
        'q6':q6_input,
    }
    
    des_folder = os.path.join(os.getcwd(), sub_folder_name)
    data_generator = data_function[sub_folder_name]
    if not os.path.exists(des_folder):
        print('Folder not exists.')
        return

    for i in range(10):
        filename = str(i+1)
        try:
            input_file = input_generator(os.path.join(des_folder, 'data', 'input', filename),
                data_generator(i))
            input_file = os.path.join(des_folder, 'data', 'input', filename)
            answer_generator(sub_folder_name, 
                os.path.join(des_folder, 'data', 'answer', filename),
                input_file)
        except Exception as e:
            print(traceback.format_exc(), end='')
