.PHONY:all
all:dict_server dict_client

dict_server:dict_server.cc tcp_thread_server.hpp tcp_socket.hpp
	g++ dict_server.cc -o dict_server -std=c++11 -lpthread
dict_client:dict_client.cc tcp_client.hpp tcp_socket.hpp
	g++ dict_client.cc -o dict_client -std=c++11 -lpthread

.PHONY:clean
clean:
	rm dict_client dict_servert

