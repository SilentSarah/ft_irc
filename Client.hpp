/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:21:36 by hmeftah           #+#    #+#             */
/*   Updated: 2023/10/15 13:05:42 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <iterator>
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

struct AddressDataClient {
	public:
		struct 	addrinfo	hints, *res;
		struct 	sockaddr_in	client_sock_data;
		socklen_t 			socket_data_size;
		int 				server_socket_fd;
};

struct ClientInfo {
    protected:
        std::string name;
        std::string hostname;
        std::string servername;
        std::string realname;
};

class Client : public AddressDataClient, public ClientInfo
{
	private:
		std::string	 	nick;
		int	 			socket_id;
		//int  channel_id;
		bool 			just_connected;
		bool			should_be_kicked;
		std::string		raw_data;
		std::string		send_buffer;
        unsigned long   user_connected_date;
		
		//bool			IsOperator;
		
	public:
		Client();
		Client(const Client& copy);
		Client(int socket_id, bool just_connected);
		Client &operator=(const Client& copy);
		~Client();

        const std::string& GetName() const;
		int			getSockID() const;
		bool		ShouldBeKicked() const;
		void		SetKickStatus(bool status);
		int			JustConnectedStatus() const;
		const std::string&	GetBuffer(void) const;
		void		SetNick(const std::string& name);
		void		SetJustConnectedStatus(bool status);
		const std::string&	GetMessageBuffer(void) const;
		void		SetBuffer(const std::string& buffer);
		void		SetMessage(const std::string& buffer);

        void    SetName(const std::string &name);
        void    SetHostname(const std::string &hostname);
        void    SetServername(const std::string &servername);
        void    SetRealname(const std::string &realname);

        const std::string& GetNameName() const;
        const std::string& GetHostname() const;
        const std::string& GetServername() const;
        const std::string& GetRealname() const;

        unsigned long   GetConnectedDate() const;
};
