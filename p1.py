def analyze_input(input_text):
  keywords = ["char", "float", "bool", "int", "for", "break", "continue"] 
  punctuation = [".", "!", ";", "?"]
  operators = ["+", "-", "*", "/", "%", "="]
  keys, ids, nums, ops, punct = 0, 0, 0, 0, 0
  for i in input_text.split(): 
    if i in keywords:
      if keys < 5:
      print(f'{i} is a keyword!\n')
      keys += 1
    elif i in punctuation:
      if punct < 5:
        print(f'{i} is a punctuation!\n')
        punct += 1 
    elif i in operators:
      if ops < 5:
        print(f'{i} is an operator!\n') 
        ops += 1
    elif i.isnumeric():
      if nums < 5:
        print(f'{i} is a number!\n')
        nums += 1
      else:
          if ids < 5:
            flag = False
          if i[0].isalpha() or i[0] == '_':
            flag = True
          for j in i[1:]:
            if j in operators or j in punctuation: 
              print(f'{i} is an invalid token!\n')
              flag = False
              break
          if flag:
            print(f'{i} is an identifier!\n') ids += 1
          else:
            print(f'{i} is an invalid token!\n')

while True:
  user_input = input("Enter your input! Enter blank next line to end: ")
  if not user_input.strip():
    break
  analyze_input(user_input)
