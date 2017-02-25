#include "mavlink_server.h"

#include <cassert>

#include <iostream>

#include <boost/bind.hpp>

namespace {

namespace ip = ::boost::asio::ip;

}  // namespace

MavlinkServer::MavlinkServer(unsigned short port)
    : socket_{io_service_, ip::udp::endpoint{ip::udp::v4(), port}} {}

MavlinkServer::~MavlinkServer() {
  try {
    stop();
  } catch (...) {}
}

void MavlinkServer::start() {
  io_service_.reset();
  io_service_future_ = std::async(std::launch::async, [this]() { this->io_service_.run(); });
  socket_.async_receive_from(
      boost::asio::buffer(buffer_, kBufferSize), sender_endpoint_,
      boost::bind(&MavlinkServer::receivedData, this, boost::asio::placeholders::error,
                  boost::asio::placeholders::bytes_transferred));
}

void MavlinkServer::stop() {
  ::boost::system::error_code error;
  socket_.shutdown(ip::udp::socket::shutdown_both, error);
  socket_.close(error);
  io_service_.stop();
  io_service_future_.wait();
  if (error) {
    throw error;
  }
}

void MavlinkServer::receivedData(const boost::system::error_code &error,
                                 size_t num_bytes) noexcept {
  if (!error) {
    if (num_bytes > 0) {
      std::cout << "Received: " << buffer_ << std::endl;
    }
  } else {
    std::cerr << "ERROR: MavlinkServer receive: " << error << std::endl;
  }
  socket_.async_receive_from(
      boost::asio::buffer(buffer_, kBufferSize), sender_endpoint_,
      boost::bind(&MavlinkServer::receivedData, this, boost::asio::placeholders::error,
                  boost::asio::placeholders::bytes_transferred));
}
