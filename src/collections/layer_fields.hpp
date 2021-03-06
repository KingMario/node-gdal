#ifndef __NODE_GDAL_LYR_FIELD_DEFN_COLLECTION_H__
#define __NODE_GDAL_LYR_FIELD_DEFN_COLLECTION_H__

// node
#include <node.h>
#include <node_object_wrap.h>

// nan
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <nan.h>
#pragma GCC diagnostic pop

// gdal
#include <gdal_priv.h>

using namespace v8;
using namespace node;

// Layer.fields : LayerFields

// Identical to FeatureDefn.fields object from the outside
// but on the inside it uses the parent layer
// to create/modify fields instead of illegally
// adding them directly to the layer definition  

namespace node_gdal {

class LayerFields: public node::ObjectWrap {
public:
	static Persistent<FunctionTemplate> constructor;

	static void Initialize(Handle<Object> target);
	static NAN_METHOD(New);
	static Handle<Value> New(Handle<Value> layer_obj);
	static NAN_METHOD(toString);

	static NAN_METHOD(get);
	static NAN_METHOD(getNames);
	static NAN_METHOD(count);
	static NAN_METHOD(add);
	static NAN_METHOD(remove);
	static NAN_METHOD(indexOf);
	static NAN_METHOD(reorder);

	// - implement in the future -
	//static NAN_METHOD(alter);

	static NAN_GETTER(layerGetter);

	LayerFields();
private:
	~LayerFields();
};

}
#endif
