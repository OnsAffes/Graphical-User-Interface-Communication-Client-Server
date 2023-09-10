#Makefile pour exécuter l'interface
buildInterface: ./UI.c
	gcc -o UI UI.c -Wall `pkg-config --cflags --libs gtk+-3.0` -export-dynamic
	./UI

#Makefile pour exécuter la partie communcation avec Tube nommé
build_Tube_nommé:Tube_nommé/client.c Tube_nommé/server.c Tube_nommé/Handlers_Cli.h Tube_nommé/Handlers_Serv.h Tube_nommé/serv_cli_fifo.h
	gcc Tube_nommé/server.c -o Tube_nommé/server
	gcc Tube_nommé/client.c -o Tube_nommé/client
	

#Démmarer l'application du tube nommé 
start_Tube_nommé_Client: 
	./Tube_nommé/client 

start_Tube_nommé_Server: 
	./Tube_nommé/server

Tube_nommé_Server : build_Tube_nommé start_Tube_nommé_Server

Tube_nommé_Client : start_Tube_nommé_Client





#Makefile pour exécuter la partie communcation avec socket TCP 
build_tcp_socket:tcp/client.c tcp/server.c 
	gcc tcp/server.c -o tcp/server
	gcc tcp/client.c -o tcp/client
	
startservertcp: 
	./tcp/server
	
	
startclienttcp: 
	./tcp/client
#Démmarer l'application TCP Socket 


tcp_server : build_tcp_socket startservertcp

tcp_client : startclienttcp







