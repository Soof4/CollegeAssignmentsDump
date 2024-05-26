import os
import glob

def count_lines_in_file(file_path):
    with open(file_path, 'r', encoding='utf-8') as file:
        return sum(1 for _ in file)

def count_lines_in_project(project_path):
    total_lines = 0
    for cs_file in glob.glob(os.path.join(project_path, '**', '*.cs'), recursive=True):
        total_lines += count_lines_in_file(cs_file)
    return total_lines

def main():
    project_path = "./"
    if not os.path.exists(project_path):
        print("The specified path does not exist.")
        return
    
    total_lines = count_lines_in_project(project_path)
    print(f"Total number of lines in the C# project: {total_lines}")

if __name__ == "__main__":
    main()

