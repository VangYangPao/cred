#!/bin/bash

rlwrap cred-wallet-cli --wallet-file wallet_m --password "" --testnet --trusted-daemon --daemon-address localhost:41181  --log-file wallet_miner.log stop_mining

