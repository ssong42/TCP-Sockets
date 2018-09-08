/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TCPclient.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 10:55:49 by ssong             #+#    #+#             */
/*   Updated: 2018/09/07 11:42:40 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for close

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

//socket, connect, listen

int main()
{
	//create socket
	int network_socket;
	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	// specify an address for the socket
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;

	int connection_status = connect(network_socket, (struct sockaddr *)
		&server_address, sizeof(server_address));
	if (connection_status == -1)
		printf("SOMESHIT WENT WRONG IN THE CONNECTION\n");

	// recieve data from server
	char server_response[256];
	recv(network_socket, &server_response, sizeof(server_response), 0);

	// print out the server's response
	printf("Data from the server: %s\n", server_response);

	// close the socket
	close(network_socket);
	return (0);
}
