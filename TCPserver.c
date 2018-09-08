/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TCPserver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 11:25:24 by ssong             #+#    #+#             */
/*   Updated: 2018/09/07 11:43:46 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// basic commands socket, bind, listen, accept

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

int main()
{
	char server_message[256] = "You have reached the server champ!";

	// create the server socket
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	// define the server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;

	//bind the socket to our specified IP and port
	bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
	
	//listen for connections
	listen(server_socket, 3);

	//accept client socket
	int client_socket;
	client_socket = accept(server_socket, NULL, NULL);

	//send information
	send(client_socket, server_message, sizeof(server_message), 0);

	// close socket
	close(server_socket);

	return (0);
}
