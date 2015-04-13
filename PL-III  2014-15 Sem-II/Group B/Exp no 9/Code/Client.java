import java.net.*;
import java.io.*;

class Client
{
 Socket skt;

 Client(String ip, int portNo)  throws Exception
 {
   //Request a connection with the server.
   skt = new Socket(ip, portNo);
 }

 static String getString()
 {
  int n;
  byte data[] = new byte[512];
  try
  {
    n = System.in.read(data);
    String temp = new String(data, 0, n-2);
    return temp;
   //2 are the last 2 bytes of enter (13,10)
  }
  catch(IOException ex)
  {} 
  return "";  
 }

 void transact() throws Exception
 {
  InputStream in = skt.getInputStream();
  OutputStream out = skt.getOutputStream();
 
  DataInputStream din = new DataInputStream(in);
  DataOutputStream dout = new DataOutputStream(out);

  //i/o with server
   
  String s, ch;
  do
  {
   System.out.println("enter data to process ");
   s = getString();
 
   dout.writeUTF(s);
   s = din.readUTF();
   System.out.println("Response : " + s) ;

   System.out.println("Continue (yes/no) ");
   ch = getString();
   dout.writeUTF(ch);
  }while(ch.equalsIgnoreCase("yes"));
  skt.close();  
 }

 public static void main(String args[])
 {
  try
  {
   String serverIp = "127.0.0.1";
   int port = 8900;

   Client c = new Client(serverIp, port);
   c.transact();
  }
  catch(Exception ex)
  {}
 }
}