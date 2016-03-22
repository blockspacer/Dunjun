#ifndef DUNJUN_COLOR_HPP
#define DUNJUN_COLOR_HPP

#include <Dunjun/Texture.hpp>

namespace Dunjun
{
	union Color // must come before render
	{
		u8 data[4];
		struct
		{
			u8 r, g, b, a;
		};
	};
}

#endif
