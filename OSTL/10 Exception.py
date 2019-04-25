# Inherit from Exception Class
class ResultIs2Exception(Exception):
   # Do Not IMPLEMENT Exception
   # Just Throw it
   pass;

def RunWithExceptionUncaughts():
   list = ['a', 0, 2, 0.5];
   for i in list:
      try:
         res = float(i);
         res = 1/res;
         if res == 2:
            print ("Result 2. Throwing Exception");
            raise ResultIs2Exception;
         print ("Result is ", res);
      # Catch A Specific Exception
      except (ResultIs2Exception):
         print ("Caught Result Is 2 Exception. Yaay");
      except:
         print ("Exception Occured");
      else:
         print ("No Exception Faced");
      finally:
         print ("Done With Exception Sequence");

RunWithExceptionUncaughts();

'''
Exception Occured
Done With Exception Sequence
Exception Occured
Done With Exception Sequence
Result is  0.5
No Exception Faced
Done With Exception Sequence
Result 2. Throwing Exception
Caught Result Is 2 Exception. Yaay
Done With Exception Sequence
'''