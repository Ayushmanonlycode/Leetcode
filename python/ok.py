# # # # s1 = "hello"
# # # # print(s1)
# # # # L = list(s1)
# # # # print(L)
# # # # L.insert(5, "y")
# # # # print(L)
# # # # s1 = " 3".join(L)
# # # # print(s1)
# # # import io

# # # s1 = "hello"
# # # sio = io.StringIO(s1)
# # # sio.seek(4)
# # # sio.write("LD")
# # # s1 = sio.getvalue()
# # # print(s1)
# # s1 = "hello"
# # s1 = s1.maketrans(" ", " ")
# # print(s1)
# # # vowel count Python program to find number of vowels in a given string.

# # h1 = str(input("Enter a string: "))
# # vowels = "aeiou"
# # h1 = h1.lower()
# # count = 0
# # for x in h1:
# #     if x in vowels:
# #         count += 1
# # print("Number of vowels:", count)
# # Python program to convert a string with binary digits to integer.

# s = str(input("Enter a binary string: "))
# count = 0
# powercount = 0
# for x in s:
#     if x == "1":
#         count += 2**powercount
#     powercount += 1
# print("Integer value:", count)

# Python program to drop all digits from a string.

mystr = "He12llo, Py00th55on!"
for x in mystr:
    if x.isdigit():
        mystr = mystr.replace(x, "")
print(mystr)
