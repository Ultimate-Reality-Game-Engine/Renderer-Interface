#ifndef ULTREALITY_RENDERING_RENDERER_INTERFACE_H
#define ULTREALITY_RENDERING_RENDERER_INTERFACE_H

#if defined(_WIN_TARGET)
	#if defined(RENDERER_INTERFACE_EXPORTS)
		#define RENDERER_INTERFACE_API __declspec(dllexport)
	#else
		#define RENDERER_INTERFACE_API __declspec(dllimport)
	#endif

	#define RENDERER_INTERFACE_CALL __cdecl
#elif defined(_linux)
	#if defined(RENDER_INTERFACE_EXPORTS)
		#define RENDERER_INTERFACE_API __attribute__((visibility("default")))
	#else
		#define RENDERER_INTERFACE_API __attribute__((visibility("default")))
	#endif

	#define RENDERER_INTERFACE_CALL __cdecl
#elif(_mac)
	#if defined(RENDER_INTERFACE_EXPORTS)
		#define RENDERER_INTERFACE_API __attribute__((visibility("default")))
	#else
		#define RENDERER_INTERFACE_API __attribute__((visibility("default")))
	#endif

	#define RENDERER_INTERFACE_CALL __cdecl
#endif

namespace UltReality::Rendering
{
	class RendererInterface
	{
	public:
		virtual ~RendererInterface() = default;

		virtual bool RENDERER_INTERFACE_CALL Initialize() = 0;
		virtual void RENDERER_INTERFACE_CALL CreateBuffer() = 0;
		virtual void RENDERER_INTERFACE_CALL Render() = 0;
		virtual void RENDERER_INTERFACE_CALL Present() = 0;
	};
}

#endif //!ULTREALITY_RENDERING_RENDERER_INTERFACE_H