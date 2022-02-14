with open('hist_copy.py','r') as file:
    filedata = file.read()

prevar = input('Enter Current Variable: ')
newvar = input('Enter Variable: ')

filedata = filedata.replace(prevar,newvar)

with open('hist_copy.py','w') as file:
    file.write(filedata)