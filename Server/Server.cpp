#include <boost/asio.hpp>
#include <iostream>
#include <string>

using boost::asio::ip::tcp;

void start_server(unsigned short port) {
    boost::asio::io_context io_context;

    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), port));

    std::cout << "Server is running on port" << port << "...  Server wait to your message from Armenia\n";

    while (true) {
        tcp::socket socket(io_context);
        acceptor.accept(socket);

        std::cout << "Client connected.\n";

        try {
            std::array<char, 1024> buffer;
            while (true) {
                std::size_t length = socket.read_some(boost::asio::buffer(buffer));
                if (length > 0) {
                    std::cout << "Received: " << std::string(buffer.data(), length) << "\n";
                    boost::asio::write(socket, boost::asio::buffer(buffer, length));
                }
            }
        }
        catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }
}

int main() {
    try {
        start_server(2195);
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return 0;
}
