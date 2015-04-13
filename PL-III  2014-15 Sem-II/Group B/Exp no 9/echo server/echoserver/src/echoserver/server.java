package echoserver;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class server {
	private static ServerSocket servSock;
	private static Socket sock;

	public static void main(String[] args) {

		try {
			System.out.println("Enter the port no. on which you want to run server : ");
			Scanner in = new Scanner(System.in);
			int port = in.nextInt();
			servSock = new ServerSocket(port);
			//System.out.println("in echo server class");
			
			
			while(true)
			{
				
				try {
					sock = servSock.accept();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				
				new Thread()
				{
					public void run() {
							try {
								PrintWriter out = new PrintWriter(sock.getOutputStream(), true);
								BufferedReader in = new BufferedReader(new InputStreamReader(sock.getInputStream()));
								String inputLine;
								//System.out.println("before while loop");
								while((inputLine = in.readLine()) != null)
								{
									System.out.println(sock.toString() + " : " + inputLine);
									out.println(inputLine);
									if(inputLine.equals("Bye"))
										break;
								}
							} catch (IOException e) {
								// TODO Auto-generated catch block
								e.printStackTrace();
							}
							try {
								sock.close();
							} catch (IOException e) {
								// TODO Auto-generated catch block
								e.printStackTrace();
							}
					};
				}.start();
				
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	
	}
}
