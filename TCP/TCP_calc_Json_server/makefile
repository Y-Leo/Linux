FLAG=-std=c++11 -lpthread -ljsoncpp
.PHONY:all
all:calc_json2_server calc_json_client

calc_json2_server:calc_json2_server.cc tcp_thread_server.hpp tcp_socket.hpp
	g++ calc_json2_server.cc -o calc_json2_server $(FLAG)
calc_json_client:calc_json_client.cc tcp_client.hpp tcp_socket.hpp
	g++ calc_json_client.cc -o calc_json_client $(FLAG)

.PHONY:clean
clean:
	rm calc_json_client calc_json2_server

