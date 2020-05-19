#include <service/address.hpp>

#include <gtest/gtest.h>

struct ServiceAddressTest : public ::testing::Test
{
  const std::string snode =
      "8zfiwpgonsu5zpddpxwdurxyb19x6r96xy4qbikff99jwsziws9y.snode";
  const std::string coinicles =
      "7okic5x5do3uh3usttnqz9ek3uuoemdrwzto1hciwim9f947or6y.coinicles";
  const std::string sub = "coiniclesnet.test";
  const std::string invalid =
      "7okic5x5do3uh3usttnqz9ek3uuoemdrwzto1hciwim9f947or6y.net";
};

TEST_F(ServiceAddressTest, TestParseBadTLD)
{
  llarp::service::Address addr;
  ASSERT_FALSE(addr.FromString(snode, ".net"));
  ASSERT_FALSE(addr.FromString(invalid, ".net"));
}

TEST_F(ServiceAddressTest, TestParseBadTLDAppenedOnEnd)
{
  llarp::service::Address addr;
  const std::string bad = coinicles + ".net";
  ASSERT_FALSE(addr.FromString(bad, ".net"));
}

TEST_F(ServiceAddressTest, TestParseBadTLDAppenedOnEndWithSubdomain)
{
  llarp::service::Address addr;
  const std::string bad = sub + "." + coinicles + ".net";
  ASSERT_FALSE(addr.FromString(bad, ".net"));
}

TEST_F(ServiceAddressTest, TestParseSNodeNotCoinicles)
{
  llarp::service::Address addr;
  ASSERT_TRUE(addr.FromString(snode, ".snode"));
  ASSERT_FALSE(addr.FromString(snode, ".coinicles"));
}

TEST_F(ServiceAddressTest, TestParseCoiniclesNotSNode)
{
  llarp::service::Address addr;
  ASSERT_FALSE(addr.FromString(coinicles, ".snode"));
  ASSERT_TRUE(addr.FromString(coinicles, ".coinicles"));
}

TEST_F(ServiceAddressTest, TestParseCoiniclesWithSubdomain)
{
  llarp::service::Address addr;
  const std::string addr_str = sub + "." + coinicles;
  ASSERT_TRUE(addr.FromString(addr_str, ".coinicles"));
  ASSERT_EQ(addr.subdomain, sub);
  ASSERT_EQ(addr.ToString(), addr_str);
};

TEST_F(ServiceAddressTest, TestParseSnodeWithSubdomain)
{
  llarp::service::Address addr;
  const std::string addr_str = sub + "." + snode;
  ASSERT_TRUE(addr.FromString(addr_str, ".snode"));
  ASSERT_EQ(addr.subdomain, sub);
  ASSERT_EQ(addr.ToString(".snode"), addr_str);
};
