#pragma once

#include <runtime/renderer/graphics/renderer/renderpass/RenderPass.h>
#include <runtime/renderer/graphics/Shader.h>
#include <runtime/renderer/scene/Scene3D.h>

namespace arcane {

	class ForwardLightingPass : public RenderPass {
	public:
		ForwardLightingPass(Scene3D *scene, bool shouldMultisample);
		ForwardLightingPass(Scene3D *scene, Framebuffer *customFramebuffer);
		virtual ~ForwardLightingPass() override;

		LightingPassOutput executeLightingPass(ShadowmapPassOutput &shadowmapData, ICamera *camera, bool renderOnlyStatic, bool useIBL);
	private:
		void bindShadowmap(Shader *shader, ShadowmapPassOutput &shadowmapData);
	private:
		bool m_AllocatedFramebuffer;
		Framebuffer *m_Framebuffer;
		Shader *m_ModelShader, *m_TerrainShader;
	};

}
