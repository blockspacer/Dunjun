

#include <Dunjun/Level.hpp>
#ifdef DUNJUN_WORLD_HPP
#define DUNJUN_WORLD_HPP
namespace Dunjun
{
	class World
	{
	public:
		Context context;

		SceneNode sceneGraph;
		SceneRenderer renderer;

		Camera mainCamera;
		Camera playerCamera;
		Camera* currentCamera = nullptr;

		SceneNode * player = nullptr;
		Level* level = nullptr;

		BaseLight ambientLight = BaseLight();
		Array<DirectionalLight> directionalLights;
		Array<PointLight> pointLights;
		Array<SpotLight> spotLights;

		bool toggleCulling = true;

		std::string consoleText = "";
		std::string consoleBuffer = "";
		bool acceptInput = true;
		bool checkForCommand = false;
		bool useConsole = false;

		World();
		virtual ~World();

		void init(Context context);

		void update(Time dt);
		void handleEvent(const Event& event);
		void render();

	private:
		World(const World&) = delete;
		World& operator=(const World&) = delete;

		//SceneNode& getSceneGraph();
		//const SceneNode& getSceneGraph() const;

		//SceneNode* getPlayer();
		//const SceneNode* getPlayer() const;
		//
		//Level* getLevel();
		//const Level* getLevel() const;
		//
		//Camera& getCurrentCamera();
		//const Camera& getCurrentCamera() const;

	};

} // end Dunjun

#endif
