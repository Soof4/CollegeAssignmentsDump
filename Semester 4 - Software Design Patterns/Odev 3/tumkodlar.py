import os

def merge_cs_files(directory_path, output_file):
    with open(output_file, 'w') as output:
        for root, _, files in os.walk(directory_path):
            for filename in files:
                if filename.endswith('_2215.cs'):
                    # Write filename as comment
                    output.write(f'// {filename}\n\n')
                    
                    # Read content from the current file
                    with open(os.path.join(root, filename), 'r') as file:
                        output.write(file.read())
                        output.write('\n\n')

# Example usage:
directory_path = './HealthFacility'
output_file = './Proje1_TumKodlar_2215.cs'

merge_cs_files(directory_path, output_file)

