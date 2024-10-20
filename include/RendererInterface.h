#ifndef RENDERER_INTERFACE_H
#define RENDERER_INTERFACE_H

class RendererInterface
{
public:
	virtual ~RendererInterface() = default;

	virtual bool Initialize() = 0;
	virtual void CreateBuffer() = 0;
	virtual void Render() = 0;
	virtual void Present() = 0;
};

#endif //!RENDERER_INTERFACE_H