#include <boost/asio.hpp>
#include <iostream>
#include <string>

using boost::asio::ip::tcp;

static void start_client(const std::string& host, unsigned short port) {
    boost::asio::io_context io_context;

    tcp::resolver resolver(io_context);
    tcp::resolver::results_type endpoints = resolver.resolve(host, std::to_string(port));

    tcp::socket socket(io_context);
    boost::asio::connect(socket, endpoints);

    std::cout << "Connected to server was okay.\n";

    std::string message;
    while (true) {
        std::cout << "Enter message to send, if you want to exit please fill the 'exit' word: ";
        std::getline(std::cin, message);

        if (message == "exit") break;

        boost::asio::write(socket, boost::asio::buffer(message));

        std::array<char, 1024> reply;
        size_t reply_length = socket.read_some(boost::asio::buffer(reply));
        std::cout << "Server replied: " << std::string(reply.data(), reply_length) << "\n";
    }
}

int main() {
    try {
        start_client("127.0.0.1", 2195);
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
