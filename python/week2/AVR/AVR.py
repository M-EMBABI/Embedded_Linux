import re
import openpyxl as xl

# Function to parse header file and extract function prototypes

def parse_header_file(header_file):
    prototypes = []
    with open(header_file, 'r') as file:
        content = file.read()
        # Extract function prototypes using regular expressions
        
##########################################################################################
        pattern = r'(\w+\s+\w+\(.*?\)\s*;)'
        matches = re.findall(pattern, content)
        for match in matches:
            prototypes.append(match.strip())
    return prototypes
###########################################################################################
# Create Excel sheet and insert prototypes with unique IDs
def insert_into_excel(prototypes):
    workbook = xl.Workbook()
    sheet = workbook.active

    # Insert headers
    sheet['A1'] = 'ID'
    sheet['B1'] = 'Prototype'

    # Insert prototypes with unique IDs
    for i, prototype in enumerate(prototypes):
        row = i + 2  # Start from row 2
        unique_id = f'IDX{i}'
        sheet[f'A{row}'] = unique_id
        sheet[f'B{row}'] = prototype

    # Save the workbook
    workbook.save('function_prototypes.xlsx')
    print('Function prototypes inserted into Excel successfully.')

# Specify the header file path
header_file = 'DIO.h'

# Parse the header file and extract function prototypes
prototypes = parse_header_file(header_file)

# Insert prototypes into Excel sheet
insert_into_excel(prototypes)
