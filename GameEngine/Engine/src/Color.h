//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#ifndef COLOR_H
#define COLOR_H

namespace Azul
{
	// matches Vec4 for casting reasons
	class Color final : public Align16
	{
	public:
		Color();
		Color(const Color &r) = default;
		Color &operator=(const Color &) = default;
		Color(float red, float green, float blue, float alpha = 1.0f);
		~Color() = default;

		void Set(float red, float green, float blue, float alpha = 1.0f);
		void Set(const Color &r);

		union
		{
			/*                             */
			/*   color  = | x  y  z  w |   */
			/*                             */

			__m128	_mv;

			// anonymous struct
			struct
			{
				float red;
				float green;
				float blue;
				float alpha;
			};
		};

	private:

	};
}

#endif

//--- End of File ---
