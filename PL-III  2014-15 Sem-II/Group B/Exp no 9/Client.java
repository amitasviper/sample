import java.net.*;
import java.io.*;

class Client
{
 Socket s ;

 Client(String ip, int port) throws Exception
 {
   //request for connection on port@ip
   s = new Socket(ip, port);
 }

 static String scanString() throws IOException
 {
  byte arr[]  = new byte[100];
  int x = System.in.read(arr); 
  String s = new String(arr, 0, x-2);
  return s;
 }

 static char scanChar() throws IOException
 {
  int x = System.in.read(); 
  System.in.skip(2);//skip 2 bytes of enter
  return (char)x;
 }



 void performIO() throws Exception
 {
  boolean flag = false;
  String a, b;
  char ch;

  InputStream ips = s.getInputStream();
  OutputStream ops = s.getOutputStream();

  DataInputStream din = new DataInputStream(ips);
  DataOutputStream dout = new DataOutputStream(ops);

  do
  {
   System.out.println("Enter a string ");
   a = scanString();
   dout.writeUTF(a);
   b = din.readUTF();
   System.out.println("Output : " + b);

   System.out.println("Continue (y/n ) : ");
   ch = scanChar();
   if(ch == 'y' || ch == 'Y')
     flag = true;
   else 
     flag = false;

   //send the flag to the server
   dout.writeBoolean(flag);

  }while(flag);

 }

 void close() throws Exception
 {
   //close the connection
   s.close();
 }

 
public static void main(String args[])
 {
  try
  {
   Client c = new Client("127.0.0.1", 8989);   
   c.performIO();
  }
  catch(Exception ex)
  {
   System.out.println("Err : "+ ex);
  }
 }
}
