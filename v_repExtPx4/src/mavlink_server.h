#ifndef V_REPEXTPX4_MAVLINK_SERVER_H_
#define V_REPEXTPX4_MAVLINK_SERVER_H_

#include <future>

#include <boost/asio.hpp>

class MavlinkServer {
 public:
  MavlinkServer(unsigned short port);
  ~MavlinkServer();
  /// Starts the server if it is no already running.
  /// @throws std::exception if there was an error while trying to start the server.
  void start();
  /// Stops the server if it is running.
  /// @throws std::exception if there was an error while closing the socket. Note that the socket
  ///         connection will still be properly shut down when an exception is thrown.
  void stop();

 private:
  /// Called on the asio network thread when new data was received. Data will be stored in buffer_.
  void receivedData(const ::boost::system::error_code &error, size_t num_bytes) noexcept;
  /// Called on the asio network thread when data was sent.
  void sentData(const ::boost::system::error_code &error, size_t num_bytes) noexcept;

  ::boost::asio::io_service io_service_;
  std::future<void> io_service_future_;
  ::boost::asio::ip::udp::socket socket_;
  ::boost::asio::ip::udp::endpoint sender_endpoint_;
  static constexpr int kBufferSize{2048};
  char buffer_[kBufferSize];
};

#endif  // V_REPEXTPX4_MAVLINK_SERVER_H_
