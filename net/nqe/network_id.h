// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NET_NQE_NETWORK_ID_H_
#define NET_NQE_NETWORK_ID_H_

#include <string>

#include "net/base/net_export.h"
#include "net/base/network_change_notifier.h"

namespace net {
namespace nqe {
namespace internal {

// NetworkID is used to uniquely identify a network.
// For the purpose of network quality estimation and caching, a network is
// uniquely identified by a combination of |type| and
// |id|. This approach is unable to distinguish networks with
// same name (e.g., different Wi-Fi networks with same SSID).
// This is a protected member to expose it to tests.
struct NET_EXPORT_PRIVATE NetworkID {
  static NetworkID FromString(const std::string& network_id);

  NetworkID(NetworkChangeNotifier::ConnectionType type, const std::string& id);
  NetworkID(const NetworkID& other);
  ~NetworkID();

  bool operator==(const NetworkID& other) const;

  bool operator!=(const NetworkID& other) const;

  NetworkID& operator=(const NetworkID& other);

  // Overloaded to support ordered collections.
  bool operator<(const NetworkID& other) const;

  std::string ToString() const;

  // Connection type of the network.
  NetworkChangeNotifier::ConnectionType type;

  // Name of this network. This is set to:
  // - Wi-Fi SSID if the device is connected to a Wi-Fi access point and the
  //   SSID name is available, or
  // - MCC/MNC code of the cellular carrier if the device is connected to a
  //   cellular network, or
  // - "Ethernet" in case the device is connected to ethernet.
  // - An empty string in all other cases or if the network name is not
  //   exposed by platform APIs.
  std::string id;
};

}  // namespace internal
}  // namespace nqe
}  // namespace net

#endif  // NET_NQE_NETWORK_ID_H_
