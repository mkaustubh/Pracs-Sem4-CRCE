from tkinter import *

window = Tk()
window.title("Welcome to TutorialsPoint")
window.configure(background = "light green")

name = Label(window ,text = "Name")
name.grid(row = 0,column = 0)
roll = Label(window ,text = "Roll Number")
roll.grid(row = 1,column = 0)
phone = Label(window ,text = "Cell No")
phone.grid(row = 2,column = 0)
email = Label(window ,text = "Email ID")
email.grid(row = 3,column = 0)

name_f = Entry(window)
name_f.grid(row = 0,column = 2)
roll_f = Entry(window)
roll_f.grid(row = 1,column = 2)
phone_f = Entry(window)
phone_f.grid(row = 2,column = 2)
email_f = Entry(window)
email_f.grid(row = 3,column = 2)




def printd():
   print("The name of student is  ",name_f.get())
   print("The roll no of student is  ",roll_f.get())
   print("The phone no of student is  ",phone_f.get())
   print("The email of student is  ",email_f.get())


btn1 = Button(window ,text="Submit",command = printd)
btn1.grid(row=4,column=0)


window.mainloop()