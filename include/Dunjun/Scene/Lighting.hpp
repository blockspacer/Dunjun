#ifndef DUNJUN_SCENE_LIGHTING_HPP 
#define DUNJUN_SCENE_LIGHTING_HPP 

#include <Dunjun/RenderComponent.hpp>

namespace Dunjun
{
	struct Attenuation
	{
		f32 constant = 1.0f;
		f32 linear = 0.00f;
		f32 quadratic = 1.0f;
	};

	struct BaseLight
	{
		Color color = ColorLib::White;
		f32 intensity = 1.0f; // color intensity = max(color component) * brightness
		u8 brightness = 255; // perceived brightness
		Vector3 colorIntensity = {1, 1, 1};
	};

	struct DirectionalLight : BaseLight
	{
		Vector3 direction;
	};

	// TODO: fix light fall off: it doens't fall off at the same rate on y axis as on the others
	struct PointLight : BaseLight
	{
		Vector3 position = {0, 0, 0};
		Attenuation attenuation = {};
		f32 range = 16.0f;
	};

	inline Vector3 calculateLightIntensities(Color color, f32 strength)
	{
		Vector3 c = {color.r, color.g, color.b};

		return (c / (COLOR_DEPTH - 1)) * strength;
	}

	inline f32 calculateLightRange(f32 intensity, Color color, Attenuation attenuation)
	{
		f32 i = intensity * (f32)Math::max(color.r, Math::max(color.g, color.b));

		f32 r = -attenuation.linear +
				Math::sqrt(attenuation.linear * attenuation.linear -
						   4.0f * attenuation.quadratic * 
						   (attenuation.constant - i));
		r /= 2.0f * attenuation.quadratic;

		return r;
	}

	struct SpotLight : PointLight
	{
		Radian coneAngle = Radian(0.35f);
		Vector3 direction = {0, 0, -1};
	};


} // end Dunjun

#endif
