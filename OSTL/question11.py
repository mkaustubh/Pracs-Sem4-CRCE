def reverse(str):
    s = ""
    for ch in str:
        s = ch + s
    return s

mystr = str(input("Enter a String: "))
print("Reversed String: ", reverse(mystr))

