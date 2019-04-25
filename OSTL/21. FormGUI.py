from tkinter import *

class GUIForm:

    def __init__(self, master):
        # master is the tkinter object
        self.master = master
        master.title("GUI FORM")

        # Labels are used to display some text or image (Arguments: tkinter object(master), Text to be displayed(text="Name"))
        # Entry is used to take text input from user(Arguments: tkinter object)
        #create labels and entry for name,age and phone number

        self.name = Label(master, text="Name") 
        self.name_field = Entry(master) 
     
        self.age = Label(master, text="Age") 
        self.age_field = Entry(master)

        #create two radio buttons for gender (Arguments: tkinter obj, text)
        #we need to create new radio button for every new option (two radio buttons for two genders,etc)
        self.gen = Label(master, text="Gender")
        self.mgen = Radiobutton(master, text='Male')
        self.fgen = Radiobutton(master, text='Female')

        self.num = Label(master, text="Contact no.")
        self.num_field = Entry(master) 

        #Add a button to submit form
        self.close_button = Button(master, text="Submit")

    def createlayout(self):
    
        #layout is similar to placing each element in a table cell
        #for example Label name is placed at (1,0) i.e row 1 column 0
        #Label is followed by Entry field which occupies row 1 and column 1 and 2
        #i.e (1,1) and (1,2)
        # similar to html tables we can use columnspan to merge two columns
        #arguments for grid are: row,column,columnspan = no. of columns to be merged

        self.name.grid(row=1,column=0)
        self.name_field.grid(row=1, column=1,columnspan = 2)

        self.age.grid(row=2,column=0)
        self.age_field.grid(row=2, column=1,columnspan = 2)

        self.gen.grid(row=3,column=0)
        self.mgen.grid(row=3,column=1)
        self.fgen.grid(row=3,column=2)

        self.num.grid(row=4,column=0)
        self.num_field.grid(row=4, column=1,columnspan = 2)

        self.close_button.grid(row=5, column=1)

#create tkinter object
root = Tk()

#create GUIForm object
my_gui = GUIForm(root)

#call createlayout function
my_gui.createlayout()

#root.mainloop() is a method on the main window which we execute when we want to run our application. 
#his method will loop forever, waiting for events from the user
#it waits tilluntil the user exits the program – either by closing the window, or terminating the program with keyboard interrupt
root.mainloop()
