//#line 2 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"
// *********************************************************
// 
// File autogenerated for the opencv_apps package 
// by the dynamic_reconfigure package.
// Please do not edit.
// 
// ********************************************************/

#ifndef __opencv_apps__FACERECOGNITIONCONFIG_H__
#define __opencv_apps__FACERECOGNITIONCONFIG_H__

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace opencv_apps
{
  class FaceRecognitionConfigStatics;
  
  class FaceRecognitionConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l, 
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }
      
      virtual void clamp(FaceRecognitionConfig &config, const FaceRecognitionConfig &max, const FaceRecognitionConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const FaceRecognitionConfig &config1, const FaceRecognitionConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, FaceRecognitionConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const FaceRecognitionConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, FaceRecognitionConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const FaceRecognitionConfig &config) const = 0;
      virtual void getValue(const FaceRecognitionConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;
    
    template <class T>
    class ParamDescription : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string name, std::string type, uint32_t level, 
          std::string description, std::string edit_method, T FaceRecognitionConfig::* f) :
        AbstractParamDescription(name, type, level, description, edit_method),
        field(f)
      {}

      T (FaceRecognitionConfig::* field);

      virtual void clamp(FaceRecognitionConfig &config, const FaceRecognitionConfig &max, const FaceRecognitionConfig &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;
        
        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const FaceRecognitionConfig &config1, const FaceRecognitionConfig &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, FaceRecognitionConfig &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const FaceRecognitionConfig &config) const
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, FaceRecognitionConfig &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const FaceRecognitionConfig &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const FaceRecognitionConfig &config, boost::any &val) const
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, FaceRecognitionConfig &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); ++i)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    template<class T, class PT>
    class GroupDescription : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string name, std::string type, int parent, int id, bool s, T PT::* f) : AbstractGroupDescription(name, type, parent, id, s), field(f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }

      virtual void updateParams(boost::any &cfg, FaceRecognitionConfig &top) const
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->setParams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T (PT::* field);
      std::vector<FaceRecognitionConfig::AbstractGroupDescriptionConstPtr> groups;
    };
    
class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(FaceRecognitionConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);

        if("model_method"==(*_i)->name){model_method = boost::any_cast<std::string>(val);}
        if("use_saved_data"==(*_i)->name){use_saved_data = boost::any_cast<bool>(val);}
        if("save_train_data"==(*_i)->name){save_train_data = boost::any_cast<bool>(val);}
        if("data_dir"==(*_i)->name){data_dir = boost::any_cast<std::string>(val);}
        if("face_model_width"==(*_i)->name){face_model_width = boost::any_cast<int>(val);}
        if("face_model_height"==(*_i)->name){face_model_height = boost::any_cast<int>(val);}
        if("face_padding"==(*_i)->name){face_padding = boost::any_cast<double>(val);}
        if("model_num_components"==(*_i)->name){model_num_components = boost::any_cast<int>(val);}
        if("model_threshold"==(*_i)->name){model_threshold = boost::any_cast<double>(val);}
        if("lbph_radius"==(*_i)->name){lbph_radius = boost::any_cast<int>(val);}
        if("lbph_neighbors"==(*_i)->name){lbph_neighbors = boost::any_cast<int>(val);}
        if("lbph_grid_x"==(*_i)->name){lbph_grid_x = boost::any_cast<int>(val);}
        if("lbph_grid_y"==(*_i)->name){lbph_grid_y = boost::any_cast<int>(val);}
      }
    }

    std::string model_method;
bool use_saved_data;
bool save_train_data;
std::string data_dir;
int face_model_width;
int face_model_height;
double face_padding;
int model_num_components;
double model_threshold;
int lbph_radius;
int lbph_neighbors;
int lbph_grid_x;
int lbph_grid_y;

    bool state;
    std::string name;

    
}groups;



//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      std::string model_method;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool use_saved_data;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool save_train_data;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      std::string data_dir;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int face_model_width;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int face_model_height;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double face_padding;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int model_num_components;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double model_threshold;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int lbph_radius;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int lbph_neighbors;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int lbph_grid_x;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int lbph_grid_y;
//#line 218 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("FaceRecognitionConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }
    
    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }
    
    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const FaceRecognitionConfig &__max__ = __getMax__();
      const FaceRecognitionConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const FaceRecognitionConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->calcLevel(level, config, *this);
      return level;
    }
    
    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const FaceRecognitionConfig &__getDefault__();
    static const FaceRecognitionConfig &__getMax__();
    static const FaceRecognitionConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();
    
  private:
    static const FaceRecognitionConfigStatics *__get_statics__();
  };
  
  template <> // Max and min are ignored for strings.
  inline void FaceRecognitionConfig::ParamDescription<std::string>::clamp(FaceRecognitionConfig &config, const FaceRecognitionConfig &max, const FaceRecognitionConfig &min) const
  {
    return;
  }

  class FaceRecognitionConfigStatics
  {
    friend class FaceRecognitionConfig;
    
    FaceRecognitionConfigStatics()
    {
FaceRecognitionConfig::GroupDescription<FaceRecognitionConfig::DEFAULT, FaceRecognitionConfig> Default("Default", "", 0, 0, true, &FaceRecognitionConfig::groups);
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.model_method = "";
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.model_method = "";
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.model_method = "eigen";
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(FaceRecognitionConfig::AbstractParamDescriptionConstPtr(new FaceRecognitionConfig::ParamDescription<std::string>("model_method", "str", 0, "Method to recognize faces", "{'enum_description': 'Method to recognize faces', 'enum': [{'srcline': 41, 'description': 'eigen', 'srcfile': '/home/riki/catkin_ws/src/opencv_apps/cfg/FaceRecognition.cfg', 'cconsttype': 'const char * const', 'value': 'eigen', 'ctype': 'std::string', 'type': 'str', 'name': 'eigen'}, {'srcline': 42, 'description': 'fisher', 'srcfile': '/home/riki/catkin_ws/src/opencv_apps/cfg/FaceRecognition.cfg', 'cconsttype': 'const char * const', 'value': 'fisher', 'ctype': 'std::string', 'type': 'str', 'name': 'fisher'}, {'srcline': 43, 'description': 'LBPH', 'srcfile': '/home/riki/catkin_ws/src/opencv_apps/cfg/FaceRecognition.cfg', 'cconsttype': 'const char * const', 'value': 'LBPH', 'ctype': 'std::string', 'type': 'str', 'name': 'LBPH'}]}", &FaceRecognitionConfig::model_method)));
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(FaceRecognitionConfig::AbstractParamDescriptionConstPtr(new FaceRecognitionConfig::ParamDescription<std::string>("model_method", "str", 0, "Method to recognize faces", "{'enum_description': 'Method to recognize faces', 'enum': [{'srcline': 41, 'description': 'eigen', 'srcfile': '/home/riki/catkin_ws/src/opencv_apps/cfg/FaceRecognition.cfg', 'cconsttype': 'const char * const', 'value': 'eigen', 'ctype': 'std::string', 'type': 'str', 'name': 'eigen'}, {'srcline': 42, 'description': 'fisher', 'srcfile': '/home/riki/catkin_ws/src/opencv_apps/cfg/FaceRecognition.cfg', 'cconsttype': 'const char * const', 'value': 'fisher', 'ctype': 'std::string', 'type': 'str', 'name': 'fisher'}, {'srcline': 43, 'description': 'LBPH', 'srcfile': '/home/riki/catkin_ws/src/opencv_apps/cfg/FaceRecognition.cfg', 'cconsttype': 'const char * const', 'value': 'LBPH', 'ctype': 'std::string', 'type': 'str', 'name': 'LBPH'}]}", &FaceRecognitionConfig::model_method)));
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.use_saved_data = 0;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.use_saved_data = 1;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.use_saved_data = 1;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(FaceRecognitionConfig::AbstractParamDescriptionConstPtr(new FaceRecognitionConfig::ParamDescription<bool>("use_saved_data", "bool", 0, "Use saved data", "", &FaceRecognitionConfig::use_saved_data)));
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(FaceRecognitionConfig::AbstractParamDescriptionConstPtr(new FaceRecognitionConfig::ParamDescription<bool>("use_saved_data", "bool", 0, "Use saved data", "", &FaceRecognitionConfig::use_saved_data)));
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.save_train_data = 0;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.save_train_data = 1;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.save_train_data = 1;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(FaceRecognitionConfig::AbstractParamDescriptionConstPtr(new FaceRecognitionConfig::ParamDescription<bool>("save_train_data", "bool", 0, "Save train data", "", &FaceRecognitionConfig::save_train_data)));
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(FaceRecognitionConfig::AbstractParamDescriptionConstPtr(new FaceRecognitionConfig::ParamDescription<bool>("save_train_data", "bool", 0, "Save train data", "", &FaceRecognitionConfig::save_train_data)));
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.data_dir = "";
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.data_dir = "";
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.data_dir = "~/.ros/opencv_apps/face_data";
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(FaceRecognitionConfig::AbstractParamDescriptionConstPtr(new FaceRecognitionConfig::ParamDescription<std::string>("data_dir", "str", 0, "Save directory for train data", "", &FaceRecognitionConfig::data_dir)));
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(FaceRecognitionConfig::AbstractParamDescriptionConstPtr(new FaceRecognitionConfig::ParamDescription<std::string>("data_dir", "str", 0, "Save directory for train data", "", &FaceRecognitionConfig::data_dir)));
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.face_model_width = 30;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.face_model_width = 500;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.face_model_width = 190;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(FaceRecognitionConfig::AbstractParamDescriptionConstPtr(new FaceRecognitionConfig::ParamDescription<int>("face_model_width", "int", 0, "Width of training face image", "", &FaceRecognitionConfig::face_model_width)));
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(FaceRecognitionConfig::AbstractParamDescriptionConstPtr(new FaceRecognitionConfig::ParamDescription<int>("face_model_width", "int", 0, "Width of training face image", "", &FaceRecognitionConfig::face_model_width)));
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.face_model_height = 30;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.face_model_height = 500;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.face_model_height = 90;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(FaceRecognitionConfig::AbstractParamDescriptionConstPtr(new FaceRecognitionConfig::ParamDescription<int>("face_model_height", "int", 0, "Height of training face image", "", &FaceRecognitionConfig::face_model_height)));
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(FaceRecognitionConfig::AbstractParamDescriptionConstPtr(new FaceRecognitionConfig::ParamDescription<int>("face_model_height", "int", 0, "Height of training face image", "", &FaceRecognitionConfig::face_model_height)));
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.face_padding = 0.0;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.face_padding = 2.0;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.face_padding = 0.1;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(FaceRecognitionConfig::AbstractParamDescriptionConstPtr(new FaceRecognitionConfig::ParamDescription<double>("face_padding", "double", 0, "Padding ratio of each face", "", &FaceRecognitionConfig::face_padding)));
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(FaceRecognitionConfig::AbstractParamDescriptionConstPtr(new FaceRecognitionConfig::ParamDescription<double>("face_padding", "double", 0, "Padding ratio of each face", "", &FaceRecognitionConfig::face_padding)));
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.model_num_components = 0;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.model_num_components = 100;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.model_num_components = 0;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(FaceRecognitionConfig::AbstractParamDescriptionConstPtr(new FaceRecognitionConfig::ParamDescription<int>("model_num_components", "int", 0, "Number of components for face recognizer model", "", &FaceRecognitionConfig::model_num_components)));
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(FaceRecognitionConfig::AbstractParamDescriptionConstPtr(new FaceRecognitionConfig::ParamDescription<int>("model_num_components", "int", 0, "Number of components for face recognizer model", "", &FaceRecognitionConfig::model_num_components)));
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.model_threshold = 0.0;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.model_threshold = 10000.0;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.model_threshold = 8000.0;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(FaceRecognitionConfig::AbstractParamDescriptionConstPtr(new FaceRecognitionConfig::ParamDescription<double>("model_threshold", "double", 0, "Threshold for face recognizer model", "", &FaceRecognitionConfig::model_threshold)));
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(FaceRecognitionConfig::AbstractParamDescriptionConstPtr(new FaceRecognitionConfig::ParamDescription<double>("model_threshold", "double", 0, "Threshold for face recognizer model", "", &FaceRecognitionConfig::model_threshold)));
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.lbph_radius = 1;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.lbph_radius = 10;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.lbph_radius = 1;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(FaceRecognitionConfig::AbstractParamDescriptionConstPtr(new FaceRecognitionConfig::ParamDescription<int>("lbph_radius", "int", 0, "Radius parameter used only for LBPH model", "", &FaceRecognitionConfig::lbph_radius)));
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(FaceRecognitionConfig::AbstractParamDescriptionConstPtr(new FaceRecognitionConfig::ParamDescription<int>("lbph_radius", "int", 0, "Radius parameter used only for LBPH model", "", &FaceRecognitionConfig::lbph_radius)));
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.lbph_neighbors = 1;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.lbph_neighbors = 30;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.lbph_neighbors = 8;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(FaceRecognitionConfig::AbstractParamDescriptionConstPtr(new FaceRecognitionConfig::ParamDescription<int>("lbph_neighbors", "int", 0, "Neighbors parameter used only for LBPH model", "", &FaceRecognitionConfig::lbph_neighbors)));
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(FaceRecognitionConfig::AbstractParamDescriptionConstPtr(new FaceRecognitionConfig::ParamDescription<int>("lbph_neighbors", "int", 0, "Neighbors parameter used only for LBPH model", "", &FaceRecognitionConfig::lbph_neighbors)));
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.lbph_grid_x = 1;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.lbph_grid_x = 30;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.lbph_grid_x = 8;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(FaceRecognitionConfig::AbstractParamDescriptionConstPtr(new FaceRecognitionConfig::ParamDescription<int>("lbph_grid_x", "int", 0, "grid_x parameter used only for LBPH model", "", &FaceRecognitionConfig::lbph_grid_x)));
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(FaceRecognitionConfig::AbstractParamDescriptionConstPtr(new FaceRecognitionConfig::ParamDescription<int>("lbph_grid_x", "int", 0, "grid_x parameter used only for LBPH model", "", &FaceRecognitionConfig::lbph_grid_x)));
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.lbph_grid_y = 1;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.lbph_grid_y = 30;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.lbph_grid_y = 8;
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(FaceRecognitionConfig::AbstractParamDescriptionConstPtr(new FaceRecognitionConfig::ParamDescription<int>("lbph_grid_y", "int", 0, "grid_y parameter used only for LBPH model", "", &FaceRecognitionConfig::lbph_grid_y)));
//#line 280 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(FaceRecognitionConfig::AbstractParamDescriptionConstPtr(new FaceRecognitionConfig::ParamDescription<int>("lbph_grid_y", "int", 0, "grid_y parameter used only for LBPH model", "", &FaceRecognitionConfig::lbph_grid_y)));
//#line 235 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 235 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(FaceRecognitionConfig::AbstractGroupDescriptionConstPtr(new FaceRecognitionConfig::GroupDescription<FaceRecognitionConfig::DEFAULT, FaceRecognitionConfig>(Default)));
//#line 353 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

      for (std::vector<FaceRecognitionConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__); 
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__); 
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__); 
    }
    std::vector<FaceRecognitionConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<FaceRecognitionConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    FaceRecognitionConfig __max__;
    FaceRecognitionConfig __min__;
    FaceRecognitionConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const FaceRecognitionConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static FaceRecognitionConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &FaceRecognitionConfig::__getDescriptionMessage__() 
  {
    return __get_statics__()->__description_message__;
  }

  inline const FaceRecognitionConfig &FaceRecognitionConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }
  
  inline const FaceRecognitionConfig &FaceRecognitionConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }
  
  inline const FaceRecognitionConfig &FaceRecognitionConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }
  
  inline const std::vector<FaceRecognitionConfig::AbstractParamDescriptionConstPtr> &FaceRecognitionConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<FaceRecognitionConfig::AbstractGroupDescriptionConstPtr> &FaceRecognitionConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const FaceRecognitionConfigStatics *FaceRecognitionConfig::__get_statics__()
  {
    const static FaceRecognitionConfigStatics *statics;
  
    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = FaceRecognitionConfigStatics::get_instance();
    
    return statics;
  }

//#line 41 "/home/riki/catkin_ws/src/opencv_apps/cfg/FaceRecognition.cfg"
      const char * const FaceRecognition_eigen = "eigen";
//#line 42 "/home/riki/catkin_ws/src/opencv_apps/cfg/FaceRecognition.cfg"
      const char * const FaceRecognition_fisher = "fisher";
//#line 43 "/home/riki/catkin_ws/src/opencv_apps/cfg/FaceRecognition.cfg"
      const char * const FaceRecognition_LBPH = "LBPH";
}

#endif // __FACERECOGNITIONRECONFIGURATOR_H__
