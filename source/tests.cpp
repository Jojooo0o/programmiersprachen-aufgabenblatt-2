#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"

TEST_CASE("describe_default_constructor", "[constructor vec2]")
{
	Vec2 v;
	REQUIRE(0.0f == v.x);
	REQUIRE(0.0f == v.y);
}

TEST_CASE("describe_custom_constructor", "[constructor vec2]")
{
	Vec2 v{1.5f, 2.5f};
	REQUIRE(1.5f == v.x);
	REQUIRE(2.5f == v.y);
}

TEST_CASE("describe_vektor_add", "[add vec2]")
{
	Vec2 v{1.5f, 2.5f};
	Vec2 w{1.5f, 2.5f};

	v += w;

	REQUIRE(Approx(3.0f) == v.x);
	REQUIRE(Approx(5.0f) == v.y);
}

TEST_CASE("describe_vektor_sub", "[sub vec2]")
{
	Vec2 v{1.5f, 2.1f};
	Vec2 w{1.5f, 2.3f};

	v -= w;

	REQUIRE(Approx(0.0f) == v.x);
	REQUIRE(Approx(-0.2f) == v.y);
}

TEST_CASE("describe_vektor_multi", "[multi vec2]")
{
	Vec2 v{1.5f, 2.1f};
	float w = 3.0f;

	v *= w;

	REQUIRE(Approx(4.5f) == v.x);
	REQUIRE(Approx(6.3f) == v.y);
}

TEST_CASE("describe_vektor_div", "[div vec2]")
{
	Vec2 v{3.0f, 2.0f};
	float w = 2.0f;

	v / w;

	REQUIRE(Approx(1.5f) == v.x);
	REQUIRE(Approx(1.0f) == v.y);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
