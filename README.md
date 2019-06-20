![GOSSIP Logo](https://gossipcoin.net/images/gossip_570x250-compressor.png)

# GOSSIP-Coin Core integration/staging repository
***

- Anonymized transactions using zerocoin technology
- 100% Proof of Stake 3.0 Consensus protocol, allowing very low transaction fees and energy expenditure, and staking rewards to all participants in the network
- Masternode technology used to secure the network and provide the above features
- Decentralized blockchain voting utilizing Masternode technology to form a DAO. The blockchain will distribute monthly treasury funds based on successful proposals submitted by the community and voted on by the DAO.

***
## [Website](https://gossipcoin.net) | [Forum](https://blockchaintalk.pro) | [Discord](https://discord.gg/54vDcgX) | [Telegram](https://t.me/gossipcoin) | [Twitter](https://twitter.com/gossip_core)

***
## [Here you can find actual bootstrap files for a quick sync](https://bootstrap.gossipcoin.net)

***

## Coin Specs

* Name: GOSSIPCOIN
* Ticker: GOSS
* Algo: Quark
* Block Time: 90 Seconds
* Difficulty Retargeting: 90 Seconds
* Max Coin Supply: Infinite
* Masternode Collateral: 9999
* Port: 23677
* RPC Port: 23679
* Coin Maturity: 59 Blocks
* Coin Confirmations: 6 Blocks
* Stake Maturity: 120 Minutes

## PoS Staking Requirements

| Requirement   | Details              |
|---------------|----------------------|
| Maturity      | 120 Minutes          |
| Amount        | 100 GOSS (per Input) |
| Wallet        | Unlocked for Staking |

## Rewards

![GOSSIP Rewards](https://i.imgur.com/H3PYdFU.png)

## Release Notes

### Version 2.1.1 - 2019/06/20

* Add: directory cleanup
* Add: added checkpoints
* Add: update depencies
* Add: add GOSSIP quick links to the overview page
* Add: direct link to the block explorer in the right click action of a transaction
* Fix: icons update
* Fix: update some tooltips
* Fix: update menu labels
* Fix: update mouseover text
* Fix: correction in governance
* Fix: Set the min protocol version to 79781
* Fix: stop using dummy strings in clientversion.cpp
* Add: remove amount percentages from title page
* Add: remove zGOSS from: overviewpage, help commands, some place in the wallet options
* Add: remove privacy label from the UI
* Add: set the default db cache from 100MB to 300MB
* Add: increase the default number of wallet backups from 10 to 20
* Add: build GOSSIP Core for the AARCH64 CPU architecture, so we can run the wallet on ARM v8 PC's (like Odroid)

### Version 2.1.0 - 2019/04/16

* Feature: Add proposals via wallet GUI
* Fix: Spork keys correction
* Fix: Update Gitian building from trusty to bionic
* Fix: Block time from 60 seconds to 90 seconds at block 100k
* Fix: Reduced max. outbound connections from 24 to 16 to reduce traffic
* Add: Increasing protocol version from 79780 to 79781

### Version 2.0.0 - 2019/03/17

* Initial Release

### We forked this code from the [PHORE](https://phore.io/) project. Thank you.

