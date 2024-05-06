import os

from adapter import LLMAdapter
from adapter_examples.openai_adapter import GPTAdapter


class YourLLMAdapter(LLMAdapter):
    def __init__(self, temp = 0.0):
        super().__init__()
        self.temp = temp

    def prepare_prompt(self, **kwargs):
        pass

    def prepare(self, **kwargs):
        pass

    def chat(self, **kwargs):
        pass


if __name__ == '__main__':
    # get openai key from environment variable
    api_key = os.getenv("OPENAI_API_KEY")

    # model = YourLLMAdapter(temp=0.0)
    model = GPTAdapter(temp = 0.0)
    model.prepare(
        api_key = api_key,
        model = "gpt-3.5-turbo"
    )
    model.run_all(
        api_key = api_key,
        model = "test"
    )
