# Ugly, bad hack to get around SSL issue on my Windows box
# TODO: Figure out the way to get around this, ASAP!
require 'openssl'
OpenSSL::SSL::VERIFY_PEER = OpenSSL::SSL::VERIFY_NONE