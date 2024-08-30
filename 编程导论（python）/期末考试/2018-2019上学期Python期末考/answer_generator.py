# 放到问题文件夹下直接运行。

import os
import sys
import traceback
import importlib

solution = None

def answer_generator(input_filename, output_file_handle, solution_name):
    global solution
    temp_stdin = sys.stdin
    temp_stdout = sys.stdout
    sys.stdin = open(input_filename, 'r')
    sys.stdout = output_file_handle
    if not solution:
        # solution = importlib.import_module('solution')
        solution = importlib.import_module(solution_name)
    else:
        importlib.reload(solution)
    sys.stdin = temp_stdin
    sys.stdout = temp_stdout

def file_generator(filename, solution_name):
    f = open(os.path.join('data', 'answer', str(filename)),
        'w')
    try:
        answer_generator(os.path.join('data', 'input', str(filename)),
            f,
            solution_name)
    except Exception as e:
        print(traceback.format_exc(), end='')
    finally:
        f.close()

def main(solution_name):
    for i in range(1, 11):
        file_generator(str(i)+'.txt', solution_name)

if __name__ == '__main__':
    main(sys.argv[1])
