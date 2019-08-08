.PHONY:all
all:client server

client:echo_client.cc udp_client.hpp udp_socket.hpp
	g++ echo_client.cc -o client -std=c++11

server:echo_server.cc udp_server.hpp udp_socket.hpp
	g++ echo_server.cc -o server -std=c++11

.PHONY:clean
clean:
	rm client server

