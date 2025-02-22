#include "editor.h"

#include "world/kraft_entity.h"
#include <core/kraft_engine.h>
#include <renderer/kraft_renderer_frontend.h>
#include <renderer/kraft_resource_manager.h>
#include <systems/kraft_shader_system.h>

EditorState* EditorState::Ptr = nullptr;

EditorState::EditorState()
{
    EditorState::Ptr = this;
    this->RenderSurface = kraft::g_Renderer->CreateRenderSurface("SceneView", 200.0f, 200.0f, true);

    this->RenderSurface.RelativeMousePosition = { 999999.0f, 999999.0f };
}

kraft::Entity EditorState::GetSelectedEntity()
{
    return this->CurrentWorld->GetEntity(SelectedEntity);
}

void EditorState::SetCamera(const kraft::Camera& Camera)
{
    this->CurrentWorld->Camera = Camera;
}
