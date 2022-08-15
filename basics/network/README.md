# [What's the Difference Between `localhost` and `127.0.0.1`?](https://phoenixnap.com/kb/localhost-vs-127-0-0-1)

- `localhost` is an alias used to refer to IP addresses **reserved for loopback.**
  - While IPv4 uses the last block of class A addresses (from `127.0.0.1` to `127.255.255`)
  - IPv6 reserves the first (`0:0:0:0:0:0:0:1` - or `::1`, in short) as its loopback address.
- e.g. `localhost` does not refer exclusively to `127.0.0.1` but to **a whole range of IP addresses reserved for loopback**
- IPv6 only systems do not respond to such requests since their localhost is linked to the address `::1` - so you cannot always use `127.0.0.1` for loopback.
- configuring the host file can easily link localhost with a different IP address.
  - mac: `/private/etc/hosts`
  - it is not recommended as it may crash local applications that rely on the localhost connection and break system functionality.
- Another significant difference between `localhost` and `127.0.0.1` is how the request is sent.
  - The request does not go through the network card when pinging the loopback address with the `localhost`.
  - On the other hand, running `127.0.0.1` does pass through the network card, which may be affected by firewall settings and configurations.