#pragma once

#include <librapid/config.hpp>


namespace librapid {
	#define CTYPED [[maybe_unused]] static const long double

	// π² / 6.
	CTYPED PISQRDIV6 = 1.6449340668482264364724151666460251892189499012067984377355582293;
	// 180 / π.
	CTYPED RADTODEG = 57.295779513082320876798154814105170332405472466564321549160243861;
	// π / 180.
	CTYPED DEGTORAD = 0.0174532925199432957692369076848861271344287188854172545609719144;
	// π.
	CTYPED PI = 3.1415926535897932384626433832795028841971693993751058209749445923;
	// √π.
	CTYPED SQRTPI = 1.7724538509055160272981674833411451827975494561223871282138077898;
	// τ.
	CTYPED TAU = 6.2831853071795864769252867665590057683943387987502116419498891846;
	// π / 2.
	CTYPED HALFPI = 1.5707963267948966192313216916397514420985846996875529104874722961;
	// π x 2.
	CTYPED TWOPI = 6.2831853071795864769252867665590057683943387987502116419498891846156;
	// Eulers number.
	CTYPED E = 2.7182818284590452353602874713526624977572470936999595749669676277;
	// The square root of Eulers number.
	CTYPED SQRTE = 1.6487212707001281468486507878141635716537761007101480115750793116;
	// √2.
	CTYPED SQRT2 = 1.4142135623730950488016887242096980785696718753769480731766797379;
	// √3.
	CTYPED SQRT3 = 1.7320508075688772935274463415058723669428052538103806280558069794;
	// √5.
	CTYPED SQRT5 = 2.2360679774997896964091736687312762354406183596115257242708972454;
	// The golden ratio φ.
	CTYPED GOLDENRATIO = 1.6180339887498948482045868343656381177203091798057628621354486227;
	// The Euler-Mascheroni constant, γ.
	CTYPED EULERMASCHERONI = 0.5772156649015328606065120900824024310421593359399235988057672348;
	// The Twin Primes Constant.
	CTYPED TWINPRIMES = 0.6601618158468695739278121100145557784326233602847334133194484233;
	// ln(2).
	CTYPED LN2 = 0.6931471805599453094172321214581765680755001343602552541206800094;
	// ln(3).
	CTYPED LN3 = 1.0986122886681096913952452369225257046474905578227494517346943336;
	// ln(5).
	CTYPED LN5 = 1.6094379124341003746007593332261876395256013542685177219126478914;
	// ζ(3).
	CTYPED ZETA3 = 1.2020569031595942853997381615114499907649862923404988817922715553;
	// ∛2.
	CTYPED CUBEROOT2 = 1.2599210498948731647672106072782283505702514647015079800819751121;
	// ∛3.
	CTYPED CUBEROOT3 = 1.4422495703074083823216383107801095883918692534993505775464161945;
	// the speed of light, c.
	CTYPED LIGHTSPEED = 299792458.0;
	// Gravity of Earth, denoted as g
	CTYPED EARTHGRAVITY = 9.80665;
	// Wallis Constant.
	CTYPED WALLISCONST = 2.0945514815423265914823865405793029638573061056282391803041285290;
	// The Laplace limit, λ.
	CTYPED LAPLACELIMIT = 0.6627434193491815809747420971092529070562335491150224175203925349;
	// Gauss's constant.
	CTYPED GAUSSCONST = 0.8346268416740731862814297327990468089939930134903470024498273701;
	// Cahen's constant, C.
	CTYPED CAHENSCONST = 0.6434105462883380261822543077575647632865878602682395059870309203;
	// The parabolic constant, P₂.
	CTYPED P2 = 2.2955871493926380740342980491894903875978322036385834839299753466;
	// The Dottie number.
	CTYPED DOTTIENUMBER = 0.7390851332151606416553120876738734040134117589007574649656806357;
	// The Meissel-Mertens constant.
	CTYPED MEISSELMERTENS = 0.2614972128476427837554268386086958590515666482611992061920642139;
	// Gelfond's constant e^π.
	CTYPED ETOPI = 23.140692632779269005729086367948547380266106242600211993445046409;
	// The golden angle.
	CTYPED GOLDENANGLE = 2.3999632297286533222315555066336138531249990110581150429351127507;
	// The area of the Mandelbrot fractal.
	CTYPED MANDELBROTAREA = 1.5065918849;
	// The Gieseking constant.
	CTYPED GIESEKINGCONST = 1.0149416064096536250212025542745202859416893075302997920174891067;
	// The Bloch-Landau constant.
	CTYPED BLOCHLANDAU = 0.5432589653429767069527282953006132311388632937583569889557325691;
	// The Golomb-Dickman constant.
	CTYPED GOLOMBDICKMAN = 0.6243299885435508709929363831008372441796426201805292869735519024;
	// The Feller-Tornier constant.
	CTYPED FELLERTORNIER = 0.6613170494696223352897658462741185332854752898329;
	// The 2^(√2).
	CTYPED TWOTOSQRT2 = 2.6651441426902251886502972498731398482742113137146594928359795933;
	// The Khinchin's constant.
	CTYPED KHINCHINSCONST = 2.6854520010653064453097148354817956938203822939944629530511523455;
	// Mill's constant.
	CTYPED MILLSCONST = 1.3063778838630806904686144926026057129167845851567136443680537599;
	// π / ln(2).
	CTYPED PIOVERLN2 = 4.5323601418271938096276829457166668101718614677237955841860165479;
	// Loch's constant.
	CTYPED LOCHSCONST = 0.9702701143920339257402560192100108337812847047851612866103505299;
	// Niven's constant.
	CTYPED NIVENSCONST = 1.7052111401053677642885514534345081607620276516534690999942849065;
	// Reciprocal Fibonacci constant.
	CTYPED RECIPFIBCONST = 3.3598856662431775531720113029189271796889051337319684864955538153;
	// Backhouse's constant.
	CTYPED BACKHOUSECONST = 1.4560749485826896713995953511165435576531783748471315402707024374;
	// The MRB constant.
	CTYPED MRBCONST = 0.1878596424620671202485179340542732300559030949001387861720046840;
	// Somos' quadratic recurrence constant.
	CTYPED QUADRECURR = 1.6616879496335941212958189227499507499644186350250682081897111680;
	// The plastic number.
	CTYPED PLASTICNUMBER = 1.3247179572447460259609088544780973407344040569017333645340150503;
}
