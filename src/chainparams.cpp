// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Copyright (c) 2017-2019 The Phore Developers
// Copyright (c) 2018-2019 The GOSSIP Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "libzerocoin/Params.h"
#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
    (     0, uint256("0x00000de6a05a95fb27a241808eb19636411f91455cb56f9dbb76e04cad966550"))
    (  1260, uint256("0xbeb46737a7241b5615344cf47410933097eef307c73f5ab029ae3b65c894c62b"))
    (  4862, uint256("0xb4fc63320353bfdfb0cea62eeee026dc2442e91e36b5191b2a145246e3b5acd9"))
    ( 54391, uint256("0x6b2f0e4b2fff231f3a9e27a6e3f01881db74989a59137db9db048cf403b55662"))
    (133478, uint256("0xfbbac300aa071dd58e41ffece1d750950ac33d33634326fed7ae39fb4040875c"));
static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1561046737, // * UNIX timestamp of last checkpoint block
    269408,     // * total number of transactions between genesis and last checkpoint
    1440        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of
	(0, uint256("0x00000de6a05a95fb27a241808eb19636411f91455cb56f9dbb76e04cad966550"));
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1551880800,
    0,
    1500};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of
	(0, uint256("0x00000de6a05a95fb27a241808eb19636411f91455cb56f9dbb76e04cad966550"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1551880800,
    0,
    100};

libzerocoin::ZerocoinParams* CChainParams::Zerocoin_Params() const
{
    assert(this);
    static CBigNum bnTrustedModulus;
    bnTrustedModulus.SetDec(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParams = libzerocoin::ZerocoinParams(bnTrustedModulus);

    return &ZCParams;
}

libzerocoin::ZerocoinParams* CChainParams::OldZerocoin_Params() const
{
    assert(this);
    static CBigNum bnTrustedModulus;
    bnTrustedModulus.SetHex(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParams = libzerocoin::ZerocoinParams(bnTrustedModulus);

    return &ZCParams;
}

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0xbc;
        pchMessageStart[1] = 0x7d;
        pchMessageStart[2] = 0xd8;
        pchMessageStart[3] = 0xcd;
        vAlertPubKey = ParseHex("04138e413b09f38602c6c8ac19c0157fb0c7be4dd10e0127314c883f5de32c4f0f5e9b40ac1e2f3f3a2dabce15d86d2fa4a1ea3f89e1f342add7414f0a440fb270");
        nDefaultPort = 23677;
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        nMaxReorganizationDepth = 100;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 0;
        nTargetTimespan = 2 * 45;
        nTargetSpacing = 2 * 45;
        nMaturity = 59;
        nMasternodeCountDrift = 20;
        nMaxMoneyOut = 101000101 * COIN;

        /** Height or Time Based Activations **/
        nLastPOWBlock = 333;
        nModifierUpdateBlock = 1;
        nZerocoinStartHeight = 444;

        /**
         * Build the genesis block. Note that the output of the genesis coinbase cannot
         * be spent as it did not originally exist in the database.
         *
         * CBlock(hash=00000ffd590b14, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=e0028e, nTime=1551880800, nBits=1e0ffff0, nNonce=113665, vtx=1)
         *   CTransaction(hash=e0028e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
         *     CTxIn(COutPoint(000000, -1), coinbase 00000de6a05a95fb27a241808eb19636411f91455cb56f9dbb76e04cad966550)
         *     CTxOut(nValue=50.00000000, scriptPubKey=0xA9037BAC7050C479B121CF)
         *   vMerkleTree: e0028e
         */
        const char* pszTimestamp = "GOSSIP COIN 2.0 Blockchain. We released this version in March 2019.";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 0 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("04bcffea59eb97482475f554db08f7f67c5c5a95a52a356b052d0ec87862815796be6022c33a0baf09fcd8d3ee98ebb6aa6a77fb43d716641242cfd45369a88e7d") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1551880800;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 615806;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x00000de6a05a95fb27a241808eb19636411f91455cb56f9dbb76e04cad966550"));
        assert(genesis.hashMerkleRoot == uint256("0xcbc9930b999fcd422cc3973934beaccbc34168f0ff9279cefa52ff19907d72ce"));

        vSeeds.push_back(CDNSSeedData("gossipcoin.org", "s0.gossipcoin.org"));
        vSeeds.push_back(CDNSSeedData("gossipcoin.org", "s1.gossipcoin.org"));
    	vSeeds.push_back(CDNSSeedData("gossipcoin.org", "s2.gossipcoin.org"));
        vSeeds.push_back(CDNSSeedData("s3.gossipcoin.org", "s3.gossipcoin.org"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 30 + 8);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 121 + 17);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 71 + 27);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x2d)(0x33)(0x2e).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x2d)(0x88)(0x2f).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x04)(0x6f).convert_to_container<std::vector<unsigned char> >();

        bech32_hrp = "gosm";

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;

        nPoolMaxTransactions = 3;
        strSporkKey = "0483ad4ed8505243792ebc52e344ba89d3728bff6cdd84d5281d969a91172ba50b3e4fbc1bf44579230be544788a50934a126f8d5256bbd9b31d3e908d6f5f41ef";
        strObfuscationPoolDummyAddress = "GQ2R1eXU7z9P7zmzAwbyJTyzFuL81xu5Bq";
		nRequiredMasternodeCollateral = 9999 * COIN;

        /** Zerocoin */
        zerocoinModulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
            "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
            "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
            "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
            "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
            "31438167899885040445364023527381951378636564391212010397122822120720357";

        nZerocoinLastOldParams = 99999999;    // Updated to defer zerocoin v2 for further testing.
        nMaxZerocoinSpendsPerTransaction = 7; // Assume about 20kb each
        nMinZerocoinMintFee = 1 * CENT;       // high fee required for zerocoin mints
        nMintRequiredConfirmations = 20;      // the maximum amount of confirmations until accumulated in 19
        nRequiredAccumulation = 1;            // this is towuhabohu
        nDefaultSecurityLevel = 100;          // full security level for accumulators
        nZerocoinHeaderVersion = 4;           // Block headers must be this version once zerocoin is active
        nBudgetFeeConfirmations = 6;          // Number of confirmations for the finalization fee
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x44;
        pchMessageStart[1] = 0x76;
        pchMessageStart[2] = 0x2f;
        pchMessageStart[3] = 0xba;
        vAlertPubKey = ParseHex("04418dba9c872f88d8d7fa7afe011c3e295ddeb256c307abc2969e98a6cdce8ab8b2350f5287a4d17a1f192fa261bcdb28cb291b3748dd7e2dbf1cc777beb560c1");
        nDefaultPort = 23678;
        nEnforceBlockUpgradeMajority = 51;
        nRejectBlockOutdatedMajority = 75;
        nToCheckBlockUpgradeMajority = 100;
        nMinerThreads = 0;
        nTargetTimespan = 2 * 45;
        nTargetSpacing = 2 * 45;
        nMaturity = 15;
        nMasternodeCountDrift = 4;
        nModifierUpdateBlock = 1;
        nMaxMoneyOut = 77777777 * COIN;
        nLastPOWBlock = 200;
		nLast60SecBlock = 70000;
        nZerocoinStartHeight = 222;

        nZerocoinLastOldParams = 777777;

        genesis.nTime = 1551880800;
        genesis.nNonce = 615806;

        assert(hashGenesisBlock == uint256("0x00000de6a05a95fb27a241808eb19636411f91455cb56f9dbb76e04cad966550"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 67 + 72);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 10 + 9);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 9 + 230);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x80)(0x3a)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x80)(0x3a)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x01)(0x00)(0x01)(0x80).convert_to_container<std::vector<unsigned char> >();

        bech32_hrp = "gost";

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        nPoolMaxTransactions = 2;
        strSporkKey = "04a6f55bf21741c807beee60d553eb81ecb2be8fd948f83457b35a865074fb84b3220e9fa0cde6bd8b1cbe78d9ec3558db25c639df666de87b324d570c351fac6d"; 
        strObfuscationPoolDummyAddress = "GdjRD6xUKticHaPduiiXwS44NRpE8v7zsk";
        nRequiredMasternodeCollateral = 9999 * COIN;
        nBudgetFeeConfirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short
                                     // here because we only have a 8 block finalization window on testnet
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        pchMessageStart[0] = 0xa2;
        pchMessageStart[1] = 0xcf;
        pchMessageStart[2] = 0x7e;
        pchMessageStart[3] = 0xac;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60;
        nTargetSpacing = 2 * 45;
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1551880800;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 615806;
        nMaturity = 0;
        nLastPOWBlock = 999999999; // PoS complicates Regtest because of timing issues
        nZerocoinLastOldParams = 499;
        nZerocoinStartHeight = 100;

        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 23678;
        assert(hashGenesisBlock == uint256("0x00000de6a05a95fb27a241808eb19636411f91455cb56f9dbb76e04cad966550"));

        bech32_hrp = "gosr";

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
        nRequiredAccumulation = 1;
        strSporkKey = "04a6f55bf21741c807beee60d553eb81ecb2be8fd948f83457b35a865074fb84b3220e9fa0cde6bd8b1cbe78d9ec3558db25c639df666de87b324d570c351fac6d";
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 23680;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
