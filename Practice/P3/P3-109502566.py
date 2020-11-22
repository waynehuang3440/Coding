'''
Practice 3
Name: 黃君翰
Student Number: 109502566
Course 2020-CE1003-B
'''
def create_file():
    file_name = input("Create a file: ")
    context = input("Write something: ")

    file = open(file_name , 'w')
    file.write(context)

    print("File name: "+file_name)
    print("Context: "+context)

    file.close()

create_file()


