def hasNumbers(inputString):
	return any(char.isdigit() for char in inputString)



with open("Passwords.txt") as f:
	content = f.readlines()
# you may also want to remove whitespace characters like `\n` at the end of each line
content = [x.strip() for x in content] 

filetowrite = open("Passwords_processed.txt","w")

print('content[0] = ' + content[0])

for i in range(len(content)):	
	thiscontent = content[i]
	print(thiscontent)
#	if(len(thiscontent) >= 6):
#		if (hasNumbers(thiscontent))
#			filetowrite.write(thiscontent)



f.close()
filetowrite.close()
