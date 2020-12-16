#ifndef CG_PARTICLE_EMITTER_H
#define CG_PARTICLE_EMITTER_H

#include "../cg.hpp"
#include "../math.hpp"
#include "../core/ParticleSystem.hpp"
#include "../Texture.hpp"

#include <iostream>
#include <functional>


namespace cg {
	class ParticleEmitter : public cg::Component {
	public:
		u32 max;
		u32 rate;
		bool is_emitting;
		bool is_global;
		
		cg::Texture *texture = nullptr;
		
		std::function<void(cg::core::Particle&)> spawn_func,
												 update_func;
		
		void start();
		void render();
		void update();
		
		ParticleEmitter();
		ParticleEmitter(const std::string texture_path);
		~ParticleEmitter();
		
	private:
		cg::core::ParticleSystem *particle;
	};

}

#endif // CG_PARTICLE_EMITTER_H