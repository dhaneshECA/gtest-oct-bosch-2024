class IMessageCommunicator{
  public:
      virtual int pushMessage(const std::string& message)=0;
}
