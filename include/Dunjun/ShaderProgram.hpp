#ifndef DUNJUN_SHADERPROGRAM_HPP
#define DUNJUN_SHADERPROGRAM_HPP

#include <Dunjun/Mesh.hpp>

#include <map>
#include <string>

namespace Dunjun
{
	enum class ShaderType
	{
		Vertex,
		Fragment,
	};
	class ShaderProgram : public NonCopyable
	{
	public:
		ShaderProgram(); // Progarm for the shader
		virtual ~ShaderProgram();

		bool attachShaderFromFile(ShaderType type, const std::string& filename); // get shader info from file
		bool attachShaderFromMemory(ShaderType type, const std::string& filename);

		void use() const; // use
		bool isInUse() const; // check if in use
		void stopUsing() const;
		void checkInUse() const;

		bool link();

		void bindAttribLocation(GLuint location, const std::string& name);

		GLint getAttribLocation( const std::string& name);
		GLint getUniformLocation( const std::string& name);

		void setUniform(const std::string& name, f32 x);
		void setUniform(const std::string& name, f32 x, f32 y);
		void setUniform(const std::string& name, f32 x, f32 y, f32 z);
		void setUniform(const std::string& name, f32 x, f32 y, f32 z, f32 w);
		void setUniform(const std::string& name, u32 x);
		void setUniform(const std::string& name, s32 x); // in case an interger is needed
							
		void setUniform(const std::string& name, bool x); // incase a bool is needed
						
		void setUniform(const std::string& name, const Vector2& v); // set u_model in vertex shader
		void setUniform(const std::string& name, const Vector3& v);
		void setUniform(const std::string& name, const Vector4& v);
		void setUniform(const std::string& name, const Matrix4& m);
						
		void setUniform(const std::string& name, const Quaternion& t);
		void setUniform(const std::string& name, const Transform& t);

		//readonly       V the only class that can edit
		ReadOnly<GLuint, ShaderProgram>  object; // the file
		ReadOnly<bool, ShaderProgram> isLinked;
		ReadOnly<std::string, ShaderProgram> errorLog;

	private:
		std::map<std::string, GLint> m_attribLocations;
		std::map<std::string, GLint> m_uniformLocations;


	};
}



#endif
