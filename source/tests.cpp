#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

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
	float z = 0.0f;

	v / w;

	REQUIRE(Approx(1.5f) == v.x);
	REQUIRE(Approx(1.0f) == v.y);
}

TEST_CASE("describe_2vektor_add", "[2add vec2]")
{
	Vec2 v{1.5f, 2.5f};
	Vec2 w{2.5f, 3.5f};
	Vec2 z{0.0f, 5.0f};

	REQUIRE(Approx(4.0f) == (v + w).x);
	REQUIRE(Approx(6.0f) == (v + w).y);

	REQUIRE(Approx(1.5f) == (v + z).x);
	REQUIRE(Approx(7.5f) == (v + z).y);

	REQUIRE(Approx(2.5f) == (w + z).x);
	REQUIRE(Approx(8.5f) == (w + z).y);
}

TEST_CASE("describe_2vektor_sub", "[2sub vec2]")
{
	Vec2 v{1.5f, 2.5f};
	Vec2 w{2.5f, 3.5f};
	Vec2 z{0.0f, 5.0f};

	REQUIRE(Approx(-1.0f) == (v - w).x);
	REQUIRE(Approx(-1.0f) == (v - w).y);

	REQUIRE(Approx(1.5f) == (v - z).x);
	REQUIRE(Approx(-2.5f) == (v - z).y);

	REQUIRE(Approx(2.5f) == (w - z).x);
	REQUIRE(Approx(-1.5f) == (w - z).y);
}

TEST_CASE("describe_2vektor_multi", "[2multi vec2]")
{
	Vec2 v{1.5f, 2.5f};
	Vec2 w{2.5f, 3.5f};
	Vec2 z{0.0f, 5.0f};
	float a = 2.0f;

	REQUIRE(Approx(3.0f) == (v.x * a));
	REQUIRE(Approx(5.0f) == (w.x * a));
	REQUIRE(Approx(0.0f) == (z.x * a));
	
	REQUIRE(Approx(5.0f) == (v.y * a));
	REQUIRE(Approx(7.0f) == (w.y * a));
	REQUIRE(Approx(10.0f) == (z.y * a));
}

TEST_CASE("describe_2vektor_div", "[2div vec2]")
{
	Vec2 v{4.0f, 11.0f};
	Vec2 w{2.0f, 7.0f};
	Vec2 z{0.0f, 5.0f};
	float a = 2.0f;

	REQUIRE(Approx(2.0f) == (v.x / a));
	REQUIRE(Approx(1.0f) == (w.x / a));
	REQUIRE(Approx(0.0f) == (z.x / a));
	
	REQUIRE(Approx(5.5f) == (v.y / a));
	REQUIRE(Approx(3.5f) == (w.y / a));
	REQUIRE(Approx(2.5f) == (z.y / a));
}

TEST_CASE("describe_2vektor_multi2", "[2multi2 vec2]")
{
	float a = 4.0f;
	Vec2 v{1.5f, 2.5f};
	Vec2 w{2.5f, 3.5f};
	Vec2 z{0.0f, 5.0f};

	REQUIRE(Approx(6.0f) == (a * v.x));
	REQUIRE(Approx(10.0f) == (a * w.x));
	REQUIRE(Approx(0.0f) == (a * z.x));
	
	REQUIRE(Approx(10.0f) == (a * v.y));
	REQUIRE(Approx(14.0f) == (a * w.y));
	REQUIRE(Approx(20.0f) == (a * z.y));
}

TEST_CASE("describe_matrix_multi", "[multi mat2]")
{
	//constructor-test
	Mat2 l;
	Mat2 m{1.0f, 2.0f, 3.0f, 4.0f};
	Mat2 n{4.0f, 3.0f, 2.0f, 1.0f};
	Mat2 o{2.0f, 0.0f, 2.0f, 0.0f};

	REQUIRE(Approx(1.0f) == l.a1_1);
	REQUIRE(Approx(0.0f) == l.a1_2);
	REQUIRE(Approx(0.0f) == l.a2_1);
	REQUIRE(Approx(1.0f) == l.a2_2);

	m *= n;

	REQUIRE(Approx(8.0f) == m.a1_1);
	REQUIRE(Approx(5.0f) == m.a1_2);
	REQUIRE(Approx(20.0f) == m.a2_1);
	REQUIRE(Approx(13.0f) == m.a2_2);

	m *= o;

	REQUIRE(Approx(26.0f) == m.a1_1);
	REQUIRE(Approx(0.0f) == m.a1_2);
	REQUIRE(Approx(66.0f) == m.a2_1);
	REQUIRE(Approx(0.0f) == m.a2_2);

	n *= o;
	REQUIRE(Approx(14.0f) == n.a1_1);
	REQUIRE(Approx(0.0f) == n.a1_2);
	REQUIRE(Approx(6.0f) == n.a2_1);
	REQUIRE(Approx(0.0f) == n.a2_2);
}

TEST_CASE("describe_2matrix_multi", "[2multi mat2]"){

	Mat2 m{1.0f, 2.0f, 3.0f, 4.0f};
	Mat2 n{4.0f, 3.0f, 2.0f, 1.0f};
	Mat2 o{2.0f, 0.0f, 2.0f, 0.0f};

	Mat2 a = m * n;

	REQUIRE(Approx(8.0f) == a.a1_1);
	REQUIRE(Approx(5.0f) == a.a1_2);
	REQUIRE(Approx(20.0f) == a.a2_1);
	REQUIRE(Approx(13.0f) == a.a2_2);

	Mat2 b = m * o;

	REQUIRE(Approx(6.0f) == b.a1_1);
	REQUIRE(Approx(0.0f) == b.a1_2);
	REQUIRE(Approx(14.0f) == b.a2_1);
	REQUIRE(Approx(0.0f) == b.a2_2);

	Mat2 c = n * o;
	
	REQUIRE(Approx(14.0f) == c.a1_1);
	REQUIRE(Approx(0.0f) == c.a1_2);
	REQUIRE(Approx(6.0f) == c.a2_1);
	REQUIRE(Approx(0.0f) == c.a2_2);
}


TEST_CASE("describe_matrix_vec", "[multi matvec2]"){

	Mat2 m{1.0f, 2.0f, 3.0f, 4.0f};
	Vec2 n{2.0f, 2.0f};

	Vec2 a = m * n;
	
	REQUIRE(Approx(6.0f) == a.x);
	REQUIRE(Approx(14.0f) == a.y);
}

TEST_CASE("describe_matrix_vec2", "[multi 2matvec2]"){

	Mat2 n{1.0f, 2.0f, 3.0f, 4.0f};
	Vec2 m{2.0f, 2.0f};

	Vec2 a = m * n;
	
	REQUIRE(Approx(6.0f) == a.x);
	REQUIRE(Approx(14.0f) == a.y);
}

TEST_CASE("describe_matrix_det", "[det]"){

	Mat2 n{1.0f, 2.0f, 3.0f, 4.0f};

	REQUIRE(Approx(-2.0f) == n.det());

}

TEST_CASE("describe_matrix_inverse", "[inverse]"){

	Mat2 n{1.0f, 2.0f, 3.0f, 4.0f};

	n = inverse(n);

	REQUIRE(Approx(-2.0f) == n.a1_1);
	REQUIRE(Approx(1.0f) == n.a1_2);
	REQUIRE(Approx(1.5f) == n.a2_1);
	REQUIRE(Approx(-0.5f) == n.a2_2);

}

TEST_CASE("describe_matrix_transpose", "[transpose]"){

	Mat2 n{1.0f, 2.0f, 3.0f, 4.0f};

	n = transpose(n);

	REQUIRE(Approx(1.0f) == n.a1_1);
	REQUIRE(Approx(3.0f) == n.a1_2);
	REQUIRE(Approx(2.0f) == n.a2_1);
	REQUIRE(Approx(4.0f) == n.a2_2);

}

TEST_CASE("describe_rotation", "[rotation]"){

	
	Mat2 m = make_rotation_mat2(M_PI/2);
	Vec2 v{1.0f,0.0f};

	v = v * m;

	REQUIRE(Approx(0.0f) == v.x);
	REQUIRE(Approx(1.0f) == v.y);

}

TEST_CASE("describe_color", "[color]"){
	Color black{0.0f};
	Color red{1.0f, 0.0f, 0.0f};
	//Color wrong{5.0, 0.0, 0.0};

	REQUIRE(0.0f == black.r);
	REQUIRE(0.0f == black.g);
	REQUIRE(0.0f == black.b);

	REQUIRE(1.0f == red.r);
	REQUIRE(0.0f == red.g);
	REQUIRE(0.0f == red.b);
}

TEST_CASE("describe_rectangle", "[rectangle]"){
	Rectangle r;
	Rectangle r2{2.0f, 3.0f, 1.0f, 1.0f, 0.0f};


	REQUIRE(r.get_h() == 1.0f);
	REQUIRE(r.get_w() == 2.0f);
	REQUIRE(r.get_x() == 0.0f);
	REQUIRE(r.get_y() == 0.0f);

	REQUIRE(r2.get_h() == 2.0f);
	REQUIRE(r2.get_w() == 3.0f);
	REQUIRE(r2.get_x() == 1.0f);
	REQUIRE(r2.get_y() == 1.0f);


	REQUIRE(r2.circumference() == 10.0f);
}

TEST_CASE("descricbe_circle", "[circle]"){
	Circle c;
	Circle c2{5.0f, 0.5f, 0.4f, 1.0f};

	REQUIRE(c.get_r() == 1.0f);
	REQUIRE(c.get_centerx() == 0.5f);
	REQUIRE(c.get_centery() == 0.5f);
	
	REQUIRE(c2.get_r() == 5.00f);
	REQUIRE(c2.get_centerx() == 0.5f);
	REQUIRE(c2.get_centery() == 0.4f);

	REQUIRE(c2.circumference() == Approx(10.0f*M_PI)); 
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}