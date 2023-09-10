#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>


GtkWidget *window;
GtkWidget *input_nbr;
const gchar *nombre_clients;


// Main function
int main(int argc, char *argv[])
{
    GtkBuilder *builder; // GTK Builder variable
    gtk_init(&argc, &argv); // Start GTK
   
    builder = gtk_builder_new(); // Create GTK UI Builder
    gtk_builder_add_from_file(builder, "UI.glade", NULL); // Load our UI file

    // Assign the Variables
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window")); // Load our window named Window
    input_nbr = GTK_WIDGET(gtk_builder_get_object(builder, "input_nbr"));
    
    // Essential for a GTK based program
    gtk_builder_connect_signals(builder, NULL);
    g_object_unref(builder);
   
    gtk_widget_show_all(window); // Show our window
    gtk_main(); // Run our program

    return 0; // Necessary for a c main function
}

// fonction quand l'utilisateur clique sur le bouton connexion TCP
void tcp_button()
{    
      nombre_clients = gtk_entry_get_text (GTK_ENTRY (input_nbr)); //affecter la chaine écrite dans le champs "input_nbr" a une chaine gchar "nombre_clients"
      int n = (int) atoi(nombre_clients); //convertir la chaine "nombre_clients" en un entier n
      system("gnome-terminal -- bash -c 'make tcp_server ; exec bash'");//ouvrir un terminale à l'aide de gnome et exécuter la partie du serveur TCP à partir du //
      int k;
      for(k =0;k<n;k++)
      {
      system("gnome-terminal -- bash -c 'make tcp_client ; exec bash'");//ouvrir n fois un terminale à l'aide de gnome et exécuter la partie du client TCP à partir  
      }
     
}

// fonction quand l'utilisateur clique sur le bouton Tube nommé
void pipe_button()
{
     nombre_clients = gtk_entry_get_text (GTK_ENTRY (input_nbr));//affecter la chaine écrite dans le champs "input_nbr" a une chaine gchar "nombre_clients"
	int n = (int)atoi(nombre_clients);//convertir la chaine "nombre_clients" en un entier n
   system("gnome-terminal -- bash -c 'make Tube_nommé_Server ; exec bash'");//ouvrir un terminale à l'aide de gnome et exécuter la partie du serveur Tube nommé à partir du makefile
       int l;
    for(l =0;l<n;l++)
    {
    system("gnome-terminal -- bash -c 'make Tube_nommé_Client ; exec bash'");//ouvrir n fois un terminale à l'aide de gnome et exécuter la partie du client tube nommé à partir du makefile
    }
}
